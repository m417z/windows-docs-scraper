# THERMAL_EVENT structure

## Description

Contains a thermal event.

## Members

### `Version`

The current structure version level, **THERMAL_EVENT_VERSION**.

### `Size`

The size of the structure.

### `Type`

One of the thermal event values from Ntpoapi.h: **THERMAL_EVENT_SHUTDOWN**, **THERMAL_EVENT_HIBERNATE**, or **THERMAL_EVENT_UNSPECIFIED**.

### `Temperature`

The temperature, in tenths of a degree Kelvin, that the sensor was at after crossing the trip point (or zero if unknown).

### `TripPointTemperature`

The temperature, in tenths of a degree Kelvin, of the trip point (or zero if unknown).

### `Initiator`

A pointer to a NULL-terminated, wide-character string that identifies the sensor whose threshold was crossed.

## Remarks

 Drivers use the **THERMAL_EVENT** structure to specify a thermal event. By calling the [PowerReportThermalEvent](https://learn.microsoft.com/windows/desktop/api/powrprof/nf-powrprof-powerreportthermalevent) routine, the operating system can record the thermal event in the system event log.

## See also

[Thermal management in Windows](https://learn.microsoft.com/previous-versions/dn915117(v=vs.85))