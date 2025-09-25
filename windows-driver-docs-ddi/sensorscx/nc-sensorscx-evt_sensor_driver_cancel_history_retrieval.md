# EVT_SENSOR_DRIVER_CANCEL_HISTORY_RETRIEVAL callback function

## Description

Cancels history retrieval from the sensor.

## Parameters

### `Sensor`

A reference to the sensor object.

### `pBytesWritten`

Pointer to bytes written.

## Return value

Returns NTSTATUS.

## Prototype

```cpp
//Declaration

EVT_SENSOR_DRIVER_CANCEL_HISTORY_RETRIEVAL EvtSensorDriverCancelHistoryRetrieval;

// Definition

NTSTATUS EvtSensorDriverCancelHistoryRetrieval
(
	SENSOROBJECT Sensor
	PULONG pBytesWritten
)
{...}

```