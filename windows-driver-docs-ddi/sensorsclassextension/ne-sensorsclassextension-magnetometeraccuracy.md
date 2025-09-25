# MagnetometerAccuracy enumeration

## Description

Specifies the accuracy of the magnetometer.

## Constants

### `MAGNETOMETER_ACCURACY_UNKNOWN`

The accuracy is currently not available, typically because the driver can't report it.

### `MAGNETOMETER_ACCURACY_UNRELIABLE`

The reported values have a high degree of inaccuracy. Apps should always ask the user to calibrate the device whenever this value is returned.

### `MAGNETOMETER_ACCURACY_APPROXIMATE`

The actual and reported values differ but may be accurate enough for some applications. Apps that only need a relative value, like a virtual reality app, can continue without additional calibration.

### `MAGNETOMETER_ACCURACY_HIGH`

The actual and reported values are accurate. No additional calibration is needed.

## Remarks

Device drivers that support magnetometer accuracy should only report the **MAGNETOMETER_ACCURACY_UNRELIABLE**, **MAGNETOMETER_ACCURACY_APPROXIMATE**, and **MAGNETOMETER_ACCURACY_HIGH** values.

Apps that need calibration may periodically ask the user to calibrate the device. We suggest doing this once every 10 minutes.

## See also

- [Common sensor properties](https://learn.microsoft.com/windows-hardware/drivers/sensors/sensor-properties2)