(def rate 100) ; Update rate in hz

(def A1 0)
(def A2 0)

(def current 0)
(def safestart 0)
(def safestartcount 0)

(def Vin 0)

(defun lpf (val sample)
    (- val (* (/ 5.0 rate) (- val sample)))
)

; Config
;(conf-set 'l-current-max  25)
;(conf-set 'l-current-min  -2)
;(conf-set 'foc-sensor-mode 4) ;FOC_SENSOR_MODE_HFI_START
;(conf-set 'foc-sensor-mode 8) ;FOC_SENSOR_MODE_HFI_V5

(loopwhile t {
       
        ;ADC
        (def A1 (get-adc 0))
        (def A2 (get-adc 0))
        
        ; voltage
        (def Vin (lpf Vin (get-vin)))
        
        ;set current
        ;(def current (* (- A1 0.95) 11));remove offset of 1V and x10
        (def current (/ (- A1 0.95) 1.65));remove offset of 1V and x10
        
        (if (< current 0) (def current 0) 1);no negative value, just 0
        (if (and (< A1 0.9) (= safestart 0)) (def safestartcount (+ safestartcount 1)) 0)
        (if (> safestartcount 400) (def safestart 1) 0)
    
        ;(if safestart (set-current current 0) (set-current 0 0))
        (if safestart (set-current-rel current 0) (set-current 0 0))
        
        (sleep (/ 1.0 rate))
})
