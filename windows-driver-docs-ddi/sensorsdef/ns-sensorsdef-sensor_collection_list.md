# SENSOR_COLLECTION_LIST structure

## Description

This structure contains a list of all [SENSOR_VALUE_PAIR](https://learn.microsoft.com/windows-hardware/drivers/ddi/sensorsdef/ns-sensorsdef-sensor_value_pair) structures for each sensor. This structure is returned by calling ReadFile.

## Members

### `AllocatedSizeInBytes`

Represents the number of elements allocated in List.

### `Count`

Represents the number of used entries in List.

### `List`

A list of [SENSOR_VALUE_PAIR](https://learn.microsoft.com/windows-hardware/drivers/ddi/sensorsdef/ns-sensorsdef-sensor_value_pair) structures.

## Remarks

The SENSOR_COLLECTION_LIST structure works with the following helper functions:

* [SENSOR_COLLECTION_LIST_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/sensorsdef/nf-sensorsdef-sensor_collection_list_init)
* [SENSOR_COLLECTION_LIST_SIZE](https://learn.microsoft.com/windows-hardware/drivers/ddi/sensorsdef/nf-sensorsdef-sensor_collection_list_size)
* [SENSOR_COLLECTION_LIST_CALCULATE_MAX_COUNT](https://learn.microsoft.com/windows-hardware/drivers/ddi/sensorsdef/nf-sensorsdef-sensor_collection_list_calculate_max_count)