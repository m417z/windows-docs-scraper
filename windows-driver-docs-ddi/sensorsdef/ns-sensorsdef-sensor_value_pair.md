# SENSOR_VALUE_PAIR structure

## Description

This structure pairs the property keys listed in the [Sensor properties](https://learn.microsoft.com/windows-hardware/drivers/sensors/sensor-properties2) section with the data that each key represents.

## Members

### `Key`

A property key that is associated with a sensor. For a list of the valid property keys, see [Sensor properties](https://learn.microsoft.com/windows-hardware/drivers/sensors/sensor-properties2).

### `Value`

A value that is associated with the property key element.

## Remarks

The Value is one of the VT types (VARTYPE) that are supported by the sensor class extension (CX):

* VT_I1
* VT_UI1
* VT_I2
* VT_UI2
* VT_I4
* VT_UI4
* VT_INT
* VT_UINT
* VT_R4
* VT_BOOL
* VT_DATE
* VT_FILETIME
* VT_CLSID
* VT_LPWSTR