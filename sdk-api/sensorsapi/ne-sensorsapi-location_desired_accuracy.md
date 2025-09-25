# LOCATION_DESIRED_ACCURACY enumeration

## Description

The **LOCATION_DESIRED_ACCURACY**  enumeration type defines values for the [SENSOR_PROPERTY_LOCATION_DESIRED_ACCURACY](https://learn.microsoft.com/windows-hardware/drivers/sensors/sensor-properties2) property.

## Constants

### `LOCATION_DESIRED_ACCURACY_DEFAULT:0`

Indicates that the sensor should use the accuracy for which it can optimize power and other such cost considerations.

### `LOCATION_DESIRED_ACCURACY_HIGH`

Indicates that the sensor should deliver the highest-accuracy report possible. This includes using services that might charge money, or consuming higher levels of battery power or connection bandwidth.

## See also

[ISensorDriver::OnGetProperties](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/sensorsclassextension/nf-sensorsclassextension-isensordriver-ongetproperties)