# __MIDL___MIDL_itf_windowssensorclassextension_0000_0000_0002 enumeration

## Description

The **SensorConnectionType** enumeration type defines values for the [SENSOR_CONNECTION_TYPE](https://learn.microsoft.com/windows-hardware/drivers/sensors/sensor-properties2) property.

## Constants

### `SENSOR_CONNECTION_TYPE_PC_INTEGRATED`

Indicates that the sensor is built into the computer.

### `SENSOR_CONNECTION_TYPE_PC_ATTACHED`

Indicates that the sensor is attached to the computer, such as through a peripheral device.

### `SENSOR_CONNECTION_TYPE_PC_EXTERNAL`

Indicates that the sensor is connected by external means, such as through a network connection.

## See also

[Enumeration properties](https://learn.microsoft.com/windows-hardware/drivers/sensors/enumeration-properties)

[ISensorDriver::OnGetProperties](https://learn.microsoft.com/windows-hardware/drivers/ddi/sensorsclassextension/nf-sensorsclassextension-isensordriver-ongetproperties)