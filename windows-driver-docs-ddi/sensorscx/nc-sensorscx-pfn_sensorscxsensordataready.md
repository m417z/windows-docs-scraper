# *PFN_SENSORSCXSENSORDATAREADY callback function

## Description

Notifies the class extension that the driver has retrieved data.

## Parameters

### `DriverGlobals`

Global definitions for the driver.

### `Sensor`

A reference to a sensor object.

### `pSensorData`

Pointer to a list of sensor properties.

## Prototype

```cpp
//Declaration

*PFN_SENSORSCXSENSORDATAREADY *PfnSensorscxsensordataready;

// Definition

VOID *PfnSensorscxsensordataready
(
  PSENSORSCX_DRIVER_GLOBALS DriverGlobals
  SENSOROBJECT Sensor
  PSENSOR_COLLECTION_LIST pSensorData
)
{...}

```

## Return value

This function returns an **NTSTATUS** with different values. Some values that may be returned are:

- STATUS_SUCCESS is returned if the function completes successfully.
- STATUS_UNSUCCESSFUL is returned if the function does not complete successfully.
- STATUS_INVALID_PARAMETER is returned if any of the _In_ parameters are NULL.

> [!NOTE]
> Any client that calls **SensorsCxSensorDataReady** must make sure that **SensorsCxSensorDataReady** is started, before the call is made. Calling **SensorsCxSensorDataReady** before it is started can cause the sensor class extension to become unresponsive.