# MagnetometerAccuracy enumeration

## Description

Specifies the accuracy of the magnetometer.

## Constants

### `MAGNETOMETER_ACCURACY_UNKNOWN:0`

### `MAGNETOMETER_ACCURACY_UNRELIABLE`

### `MAGNETOMETER_ACCURACY_APPROXIMATE`

### `MAGNETOMETER_ACCURACY_HIGH`

#### - Approximate

The actual and reported values differ but may be accurate enough for some application. Apps that only need a relative value, like a virtual reality app, can continue without additional calibration.

#### - High

The actual and reported values are accurate. No additional calibration is needed.

#### - Unknown

This value is not used.

#### - Unreliable

The reported values have a high degree of inaccuracy. Apps will typically ask the user to calibrate the device whenever this value is returned.

## Remarks

Apps that need calibration may periodically ask the user to calibrate the device. We suggest doing this no more than once every 10 minutes.