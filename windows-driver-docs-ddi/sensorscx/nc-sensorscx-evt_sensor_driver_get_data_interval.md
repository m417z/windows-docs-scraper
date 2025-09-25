# EVT_SENSOR_DRIVER_GET_DATA_INTERVAL callback function

## Description

This callback function returns the data interval for a specified sensor.

## Parameters

### `Sensor` [in]

A reference to a sensor object.

### `pDataRateMs` [out]

The data interval for the specified **Sensor**.

## Return value

This function returns STATUS_SUCCESS when completed successfully.

**Note** The class extension (CX) only uses the NT_SUCCESS macro to
determine if the call to the driver’s Evt function was successful,
but does not take any action if the function failed or does not return STATUS_SUCCESS.