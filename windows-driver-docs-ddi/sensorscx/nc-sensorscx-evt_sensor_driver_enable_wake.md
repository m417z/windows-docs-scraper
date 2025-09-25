# EVT_SENSOR_DRIVER_ENABLE_WAKE callback function

## Description

Callback to enable wake for the sensor.

## Parameters

### `Sensor` [in]

A reference to the sensor object.

## Return value

This function returns STATUS_SUCCESS when completed successfully.

**Note** The class extension (CX) only uses the NT_SUCCESS macro to determine if the call to the driver’s Evt function was successful, but does not take any action if the function failed or does not return STATUS_SUCCESS.

## Remarks

This DDSI function does not compulsorily have to be implemented by the driver because it is expected that some sensor drivers do not care about enabling wake on the sensor. If it not implemented the enable call is ignored and a STATUS_SUCCESS is returned. This is primarily because PKEY_Sensor_WakeCapable is implemented today and used by some sensors such as the accelerometer and the proximity sensor, and for backward compatibility, implementing this DDSI is optional.