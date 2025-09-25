# _SYNTH_REVERB_PARAMS structure

## Description

The SYNTH_REVERB_PARAMS structure contains configuration parameters.

## Members

### `fInGain`

Specifies the input gain in decibels (dB) to avoid output overflows.

### `fReverbMix`

Specifies the reverb mix in dB. 0dB specifies 100% wet reverb (no direct signal). Negative values specify a less wet signal. The coefficients are calculated so that the overall output level stays approximately constant regardless of the amount of reverb mix.

### `fReverbTime`

Specifies the reverb delay time in milliseconds.

### `fHighFreqRTRatio`

Specifies the ratio of the high frequencies to the global reverb time. Unless very 'splashy-bright' reverberations are desired, this should be set to a value less than 1.0. For example, if **dRevTime** is 1000ms and HHighFreqRTRatio is 0.1, then the decay time for high frequencies will be 100ms.