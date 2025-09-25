# _SENSOR_CONFIG structure

## Description

This structure contains information that the sensor driver passes to the class extension about each sensor.

## Members

### `Size`

The allocated size of this structure (in bytes).

### `pEnumerationList`

The list of enumerations. For more information, see [SENSOR_COLLECTION_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/sensorsdef/ns-sensorsdef-sensor_collection_list).

## Remarks

The SENSOR_CONFIG structure works with the following helper function:

* [SENSOR_CONFIG_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/sensorscx/nf-sensorscx-sensor_config_init)