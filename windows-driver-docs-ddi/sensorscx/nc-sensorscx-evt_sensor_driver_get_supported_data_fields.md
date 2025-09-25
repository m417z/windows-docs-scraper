# EVT_SENSOR_DRIVER_GET_SUPPORTED_DATA_FIELDS callback function

## Description

This callback function returns a list of data fields supported by the specified sensor. For more information about data fields see [Sensor data fields](https://learn.microsoft.com/windows-hardware/drivers/sensors/common-data-fields).

## Parameters

### `Sensor` [in]

A reference to a sensor object.

### `pDataFields` [in, out, optional]

A list of data fields that are supported by the given **Sensor**. For more information see [SENSOR_PROPERTY_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/sensorsdef/ns-sensorsdef-sensor_property_list).

### `pSize` [out]

The size of *pDataFields*.

## Return value

This function returns STATUS_SUCCESS when completed successfully.

> [!NOTE]
> The class extension (CX) only uses the NT_SUCCESS macro to determine if the call to the driver’s Evt function was successful, but does not take any action if the function failed or does not return STATUS_SUCCESS.

## Remarks

This function must be implemented by the driver and is called by the class extension.

## See also

[SENSOR_PROPERTY_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/sensorsdef/ns-sensorsdef-sensor_property_list)

[Sensor data fields](https://learn.microsoft.com/windows-hardware/drivers/sensors/common-data-fields)