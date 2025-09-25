# SENSOR_COLLECTION_LIST_SIZE function

## Description

This function returns the size of a [SENSOR_COLLECTION_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/sensorsdef/ns-sensorsdef-sensor_collection_list) structure.

## Parameters

### `Count` [in]

The number of [SENSOR_VALUE_PAIR](https://learn.microsoft.com/windows-hardware/drivers/ddi/sensorsdef/ns-sensorsdef-sensor_value_pair) elements in the [SENSOR_COLLECTION_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/sensorsdef/ns-sensorsdef-sensor_collection_list).

## Return value

The **SENSOR_COLLECTION_LIST_SIZE** function returns a ULONG value that represents the size of the list of sensor-value pairs.

## See also

[SENSOR_COLLECTION_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/sensorsdef/ns-sensorsdef-sensor_collection_list)