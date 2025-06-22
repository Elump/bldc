; from https://youtube.com/@EBikeBuilder_
; CONFIG
(define freewheeling-cur-rel-min 0.05)         ; minimum relative freewheeling current appied when freewheeling starts
(define freewheeling-cur-rel-max 0.15)         ; maximum relative freewheeling current to apply
(define freewheeling-ramp-secs 1)    ; how many seconds to ramp up freewheeling current
(define start-freewheel-throttle-val 0.01) ; test this with your throttle. Current Mode only
(define stop-rpm 1000)              ; at what RPM should freewheeling stop (when motor cant move)
(define adc-channel 0)           ; ADC channel to observe throttle (CH0 is ADC1)
(define input-deadband 0.15)      ; not sure how to read this from script yet
 
; STATE 
(define throttle-engaged 0)
(define freewheeling 0)
(define freewheeling-start nil)        ; date time when freewheeling started
(define freewheeling-cur-rel 0)            ; how much freewheeling current is being applied
 
(defun update-throttle ()
 (progn
    (define throttle-val (get-adc-decoded adc-channel))     ; reads ADC, decodes value to 0 to 1
    (if (> throttle-val input-deadband)
        (define throttle-engaged 1)
        (define throttle-engaged 0)
    )
 )
)
 
(defun update-freewheeling ()
 (progn
    ; check to start freewheeling based on throttle-val (useful to engage drivetrain in deadband)
    (if (= freewheeling 0)
        (if (and (= throttle-engaged 0) (>= throttle-val start-freewheel-throttle-val))
         (progn
            (define freewheeling 1)
            (define freewheeling-start (systime))
         )
        )
    )
    
    (define rpm (get-rpm))
    
    ; check to stop freewheeling
    (if (= freewheeling 1)
        (if (<= rpm stop-rpm)
            (define freewheeling 0) ; stop freewheeling because low rpm
            (progn
                (define freewheeling 1) ; start / continue freewheeling
                (define freewheeling-start (systime))
            )
        )
    )
 )
)
 
(defun apply-current ()
 (progn
    (if (= freewheeling 1)
     (progn
        ; ramp freewheeling power based on time since freewheeling started.
        (define secs-since-freewheeling-start (secs-since freewheeling-start))
        
        (define freewheeling-cur-rel (/ secs-since-freewheeling-start freewheeling-ramp-secs))
        (define freewheeling-cur-rel (* freewheeling-cur-rel freewheeling-cur-rel-max))
        
        (if (< freewheeling-cur-rel freewheeling-cur-rel-min)
            (define freewheeling-cur-rel freewheeling-cur-rel-min)
        )
        
        (if (> freewheeling-cur-rel freewheeling-cur-rel-max)
            (define freewheeling-cur-rel freewheeling-cur-rel-max)
        )
        
        ; apply freewheeling current if its enabled
        (set-current-rel freewheeling-cur-rel 0.11)
     )
    )
 )
)
 
; main loop
(loopwhile t
    (progn
        (update-throttle)
        (update-freewheeling)
        (apply-current)
        (sleep 0.01)
    )
)