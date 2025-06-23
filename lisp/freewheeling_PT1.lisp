; CONFIG
(define min-current 0.3)         ; freewheeling current to apply
(define start-freewheel-throttle-val 0.01) 
(define stop-rpm 100)              ; at what RPM should freewheeling stop (when motor cant move)
(define adc-channel 0)           ; ADC channel to observe throttle (CH0 is ADC1)
(define motor-cur 0)             ; current going to motor
(define input-deadband 0.15)      ; not sure how to read this from script yet
 
; STATE 
(define throttle-engaged 0)
(define freewheeling 0)
 
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
            (define freewheeling 1)
        )
    )
    
    (define rpm (get-rpm))
    
    ; check to stop freewheeling
    (if (= freewheeling 1)
        (if (<= rpm stop-rpm)
            (define freewheeling 0) ; stop freewheeling because low rpm
            (define freewheeling 1) ; start / continue freewheeling
        )
    )
    
    ; apply freewheeling current if its enabled
    (if (= freewheeling 1)
     (progn
        (set-current-rel min-current)
     )
    )
 )
)
 
; main loop
(loopwhile t
    (progn
        (update-throttle)
        (update-freewheeling)
        
        (sleep 0.01)
    )
)