(def rate 10)      ; Update rate in hz
(def loopcount 0)  ; loop counter
(def looptime 6)   ; loop time in s 

(def fwcurmax 2)
(def fwcurrent 0)

;set field weakening config
(conf-set 'foc-fw-duty-start 0.6)
(conf-set 'foc-fw-current-max  fwcurrent)

(loopwhile t {
    ;loop counter
    (def loopcount (+ loopcount 1))
    ;loop end?
    (if (>= loopcount (* rate looptime)) (progn
        (def loopcount 0)
    ) 0)
    
    (def fwcurrent (if (>= loopcount (/ (* rate looptime) 2)) (+ fwcurrent 0.1) (- fwcurrent 0.1) ))
    (if (> fwcurrent fwcurmax) (def fwcurrent fwcurmax) 0)
    (if (< fwcurrent 0) (def fwcurrent 0) 0)
    ;update fw current
    (conf-set 'foc-fw-current-max  fwcurrent)
        
    (sleep (/ 1.0 rate))
})