# EVT_SENSOR_DRIVER_START_SENSOR callback function

## Description

This callback function starts the sensor based on the default properties specified by the driver, or properties set by the class extension.

## Parameters

### `Sensor`

A reference to a sensor object.

## Return value

This function returns STATUS_SUCCESS when completed successfully.

**Note** The class extension (CX) only uses the NT_SUCCESS macro to determine if the call to the driver’s Evt function was successful, but does not take any action if the function failed or does not return STATUS_SUCCESS.

## Remarks

This function must be implemented by the driver and is called only once by the class extension.