# EVT_SENSOR_DRIVER_GET_DATA_FIELD_PROPERTIES callback function

## Description

This callback function returns the properties of a given data field associated with a sensor.

## Parameters

### `Sensor` [in]

A reference to a sensor object.

### `pDataField` [in]

A reference to a data field. For more information see [Sensor data fields](https://learn.microsoft.com/windows-hardware/drivers/sensors/common-data-fields).

### `pProperties` [in, out, optional]

A list of properties and their values for the specified **Sensor**. For more information see [SENSOR_COLLECTION_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/sensorsdef/ns-sensorsdef-sensor_collection_list)

### `pSize` [out]

The size of **pDataField**.

## Return value

This function returns **STATUS_SUCCESS** when completed successfully.

## Remarks

This function must be implemented by the driver and is called by the class extension.

> [!NOTE]
> The class extension (CX) only uses the NT_SUCCESS macro to determine if the call to the driver’s Evt function was successful, but does not take any action if the function failed or does not return STATUS_SUCCESS.

## See also

[Proximity sensor data fields](https://learn.microsoft.com/windows-hardware/drivers/sensors/proximity-sensor-data-fields)

[SENSOR_COLLECTION_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/sensorsdef/ns-sensorsdef-sensor_collection_list)

[Sensor data fields](https://learn.microsoft.com/windows-hardware/drivers/sensors/common-data-fields)