# EVT_SENSOR_DRIVER_GET_PROPERTIES callback function

## Description

This callback function returns the properties for a given sensor.

## Parameters

### `Sensor` [in]

A reference to a sensor object.

### `pProperties` [in, out, optional]

A list of properties and their values for the specified **Sensor**. For more information, see [SENSOR_COLLECTION_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/sensorsdef/ns-sensorsdef-sensor_collection_list).

### `pSize` [out]

The size of pProperties.

## Return value

This function returns STATUS_SUCCESS when completed successfully.

**Note** The class extension (CX) only uses the NT_SUCCESS macro to determine if the call to the driver’s Evt function was successful, but does not take any action if the function failed or does not return STATUS_SUCCESS.

## Remarks

This function must be implemented by the driver and is called by the class extension.