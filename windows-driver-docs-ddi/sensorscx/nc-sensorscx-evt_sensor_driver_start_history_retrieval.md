# EVT_SENSOR_DRIVER_START_HISTORY_RETRIEVAL callback function

## Description

Starts retrieving the history recorded so far in the sensor.

## Parameters

### `Sensor` [in]

A reference to a sensor object.

### `pHistory` [in, out]

Pointer to the sensor collection list.

### `HistorySizeInBytes` [in]

The size of the *pHistory*, in bytes.

## Return value

Returns NTSTATUS.

## Prototype

```cpp
//Declaration

EVT_SENSOR_DRIVER_START_HISTORY_RETRIEVAL EvtSensorDriverStartHistoryRetrieval;

// Definition

NTSTATUS EvtSensorDriverStartHistoryRetrieval
(
	SENSOROBJECT Sensor
	PSENSOR_COLLECTION_LIST pHistory
	ULONG HistorySizeInBytes
)
{...}

```