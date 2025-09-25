# *PFN_SENSORSCXSTATECHANGE callback function

## Description

Used to initialize a sensor state change.

## Parameters

### `DriverGlobals`

Global definitions for the driver.

### `Sensor`

A reference to a sensor object.

### `State`

The state of the sensor.

## Prototype

```cpp
//Declaration

*PFN_SENSORSCXSTATECHANGE *PfnSensorscxstatechange;

// Definition

VOID *PfnSensorscxstatechange
(
  PSENSORSCX_DRIVER_GLOBALS DriverGlobals
  SENSOROBJECT Sensor
  SENSOR_STATE State
)
{...}

```

## Return value

This function returns an **NTSTATUS** with different values. Some values that may be returned are:

- STATUS_SUCCESS is returned if the function completes successfully.
- STATUS_UNSUCCESSFUL is returned if the function does not complete successfully.
- STATUS_INVALID_PARAMETER is returned if any of the \_In\_ parameters are NULL.