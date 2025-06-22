(def rate 500) ; Update rate in hz


(def i1 0)
(def i2 0)
(def i3 0)
(def i0 0)
(def i1mom 0)
(def v1 0)
(def v2 0)
(def v3 0)
(def Vin 0)

(defun lpf (val sample)
    (- val (* (/ 5.0 rate) (- val sample)))
)

(loopwhile t {
        (var use-raw 0) ; Set to 1 to use ADC bits and not convert to voltage
        
        ; current
        (var i1-sample (raw-adc-current 1 1 use-raw))
        (var i2-sample (raw-adc-current 1 2 use-raw))
        (var i3-sample (raw-adc-current 1 3 use-raw))
        (def i1-sample (raw-adc-current 1 1 use-raw))
        (def i0 (lpf i0 (+ i1-sample i2-sample i3-sample)))
        (def i1 (lpf i1 (abs i1-sample)))
        (def i2 (lpf i2 (abs i2-sample)))
        (def i3 (lpf i3 (abs i3-sample)))
        
        ; voltage
        (def v1  (lpf V1 (abs (raw-adc-voltage 1 1 use-raw))))
        (def v2  (lpf V2 (abs (raw-adc-voltage 1 2 use-raw))))
        (def v3  (lpf V3 (abs (raw-adc-voltage 1 3 use-raw))))
        (def Vin (lpf Vin (get-vin)))
        
        (sleep (/ 1.0 rate))
})
