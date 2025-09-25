# __MIDL___MIDL_itf_windowssensorclassextension_0000_0000_0001 enumeration

## Description

The **SensorState** enumeration type specifies the current operational state of a sensor.

## Constants

### `SENSOR_STATE_MIN`

Reserved.

### `SENSOR_STATE_READY`

Indicates that the sensor is ready.

### `SENSOR_STATE_NOT_AVAILABLE`

Indicates that the sensor is not currently available for use.

### `SENSOR_STATE_NO_DATA`

Indicates that no data available.

### `SENSOR_STATE_INITIALIZING`

Indicates that the sensor is not yet ready for use. Try again.

### `SENSOR_STATE_ACCESS_DENIED`

Reserved. Do not use in driver code.

### `SENSOR_STATE_ERROR`

Indicates that an unspecified error occurred.

### `SENSOR_STATE_MAX`

Reserved.

## Remarks

This enumeration also defines values used for the [SENSOR_PROPERTY_STATE](https://learn.microsoft.com/windows-hardware/drivers/sensors/sensor-properties2) property.

## See also

[ISensorClassExtension::PostStateChange](https://learn.microsoft.com/windows-hardware/drivers/ddi/sensorsclassextension/nf-sensorsclassextension-isensorclassextension-poststatechange)

[ISensorDriver::OnGetProperties](https://learn.microsoft.com/windows-hardware/drivers/ddi/sensorsclassextension/nf-sensorsclassextension-isensordriver-ongetproperties)