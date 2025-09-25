# EVT_SENSOR_DRIVER_STOP_SENSOR_HISTORY callback function

## Description

Stops recording history in the sensor.

## Parameters

### `Sensor`

A reference to a sensor object.

## Return value

Returns NTSTATUS.

## Prototype

```cpp
//Declaration

EVT_SENSOR_DRIVER_STOP_SENSOR_HISTORY EvtSensorDriverStopSensorHistory;

// Definition

NTSTATUS EvtSensorDriverStopSensorHistory
(
	SENSOROBJECT Sensor
)
{...}

```