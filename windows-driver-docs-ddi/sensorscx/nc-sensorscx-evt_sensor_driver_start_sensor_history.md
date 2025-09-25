# EVT_SENSOR_DRIVER_START_SENSOR_HISTORY callback function

## Description

Starts recording history in the sensor.

## Parameters

### `Sensor` [in]

A reference to a sensor object.

## Return value

Returns NTSTATUS.

## Prototype

```cpp
//Declaration

EVT_SENSOR_DRIVER_START_SENSOR_HISTORY EvtSensorDriverStartSensorHistory;

// Definition

NTSTATUS EvtSensorDriverStartSensorHistory
(
	SENSOROBJECT Sensor
)
{...}

```