# EVT_SENSOR_DRIVER_CLEAR_SENSOR_HISTORY callback function

## Description

Clears the history recorded so far in the sensor.

## Parameters

### `Sensor`

A reference to the sensor object.

## Return value

Returns NTSTATUS.

## Prototype

```cpp
//Declaration

EVT_SENSOR_DRIVER_CLEAR_SENSOR_HISTORY EvtSensorDriverClearSensorHistory;

// Definition

NTSTATUS EvtSensorDriverClearSensorHistory
(
	SENSOROBJECT Sensor
)
{...}

```