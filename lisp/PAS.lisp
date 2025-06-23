; Single line PAS sensor waveform
;      ____          ____   
;      |  |          |  |   
;-------  ------------  ----
;         ^-pulse width-^
;
; On reverse direction of pedaling the signal is at high state all the time

; When not pedaling(or very slow) the motor is disabled
; When pedaling is detected the ADC APP is enabled and throttle sets assists current
; I removed a spring from the throttle and put a piece of felt inside so 
; the throttle stays at set position

(gpio-configure 'pin-ppm 'pin-mode-in-pd) ; use PPM input

(define MAGNETS 12)
(define MIN_PULSE 0.3) ;seconds, above this pulse width assist is disabled

(define pulse 0) ; PAS pulse width
(define last_pulse 0)

(define last_pas_pin 0)
(define last_pas_t 0)
(define assist 0)
(define assist_cnt 0)
(define pas_rpm 0)
(define riding_stops2 0) ;debug


(defun set-assist (assist1)
  (progn
    (define assist (if assist1 1 0))
    (if assist1
      (app-adc-detach 1 0) ; engage throttle current, attach ADC1 to enable the motor
      (progn ; else
        (define assist_cnt 0)
        (app-adc-detach 1 2) ; detach ADC1 to disable the motor
      )
    )
  )
)

(set-assist nil) ; disable assist at startup

; main loop
(loopwhile t ;run at 1000Hz (sleep 0.001)
  (progn
    (define pas_pin (gpio-read 'pin-ppm)) ; read PAS pin
    (if (!= pas_pin last_pas_pin)
      (if (= pas_pin 0) ; measure pulse width on falling edge
        (progn
          (define last_pulse pulse)
          (define pulse (secs-since last_pas_t))
          (define last_pas_t (systime))

          ;(define pas_rpm (* 60 (/ (/ 1.0 MAGNETS) pulse)))

          (if (and (= 0 assist) (< pulse MIN_PULSE)) ; detect pedaling when pulse is shorter than MIN_PULSE sec
            (progn
              (define assist_cnt (+ assist_cnt 1))
              (if (>= assist_cnt 2) ; enable assist when at least 2 short pulses detected
                (set-assist t)
              )
            )
          )

          (if (and (= 1 assist) (> pulse (* last_pulse 1.25))) ; detect rapid PAS slowdown
            (progn
              (set-assist nil)
              (define riding_stops2 (+ 1 riding_stops2)) ; debug
            )
          )

          ;(define pulse_change (/ pulse (+ 0.0001 last_pulse))) ; debug
        )
      )
    )
    (define last_pas_pin pas_pin)

    ; detect very-slow/not pedaling
    (if (and (= 1 assist) (> (secs-since last_pas_t) MIN_PULSE))
      (set-assist nil)
    )

    (sleep 0.001)
  )
)