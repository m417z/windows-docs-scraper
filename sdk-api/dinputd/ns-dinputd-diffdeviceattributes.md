# DIFFDEVICEATTRIBUTES structure

## Description

The DIFFDEVICEATTRIBUTES structure describes the information contained in the "Attributes" value of the **OEMForceFeedback** registry key.

## Members

### `dwFlags`

Reserved for future use. This member must be set to zero.

### `dwFFSamplePeriod`

Specifies the minimum time between playback of force commands, in microseconds.

### `dwFFMinTimeResolution`

Specifies the minimum amount of time that the device can resolve, in microseconds. The device rounds any time values to the nearest supported increment. For example, if the value of **dwFFMinTimeResolution** is 1000, then the device would round any times to the nearest millisecond.