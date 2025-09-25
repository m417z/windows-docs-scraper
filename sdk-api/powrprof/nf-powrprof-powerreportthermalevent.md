# PowerReportThermalEvent function

## Description

Notifies the operating system of thermal events.

## Parameters

### `Event` [in]

The thermal event structure, [THERMAL_EVENT](https://learn.microsoft.com/windows/desktop/api/powrprof/ns-powrprof-thermal_event).

## Return value

Returns **ERROR_SUCCESS** (zero) if the call was successful, and a nonzero value if
the call failed.

## Remarks

Thermal managers call the **PowerReportThermalEvent** routine to notify the operating system of a thermal event so that the event can be recorded in the system event log.

Before calling **PowerReportThermalEvent**, the thermal manager sets the members of the [THERMAL_EVENT](https://learn.microsoft.com/windows/desktop/api/powrprof/ns-powrprof-thermal_event) structure to describe the thermal event.

## See also

[Thermal management in Windows](https://learn.microsoft.com/previous-versions/dn915117(v=vs.85))