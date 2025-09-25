# *PFN_SENSORSCXSENSORHISTORYRETRIEVALCOMPLETED callback function

## Description

Indicates that the history retrieval has completed.

## Parameters

### `DriverGlobals` [in]

Global definitions for the driver.

### `Sensor` [in]

A reference to a sensor object.

### `BytesWritten` [in]

The number of bytes written to the sensor object's history.

### `InStatus` [in]

The current status of the sensor object.

## Prototype

```cpp
//Declaration

*PFN_SENSORSCXSENSORHISTORYRETRIEVALCOMPLETED *PfnSensorscxsensorhistoryretrievalcompleted;

// Definition

VOID *PfnSensorscxsensorhistoryretrievalcompleted
(
  PSENSORSCX_DRIVER_GLOBALS DriverGlobals
  SENSOROBJECT Sensor
  ULONG BytesWritten
  NTSTATUS InStatus
)
{...}

```

## Return value

This function returns an **NTSTATUS** with different values. Some values that may be returned are:

- STATUS_SUCCESS is returned if the function completes successfully.
- STATUS_UNSUCCESSFUL is returned if the function does not complete successfully.
- STATUS_INVALID_PARAMETER is returned if any of the \_In\_ parameters are NULL.