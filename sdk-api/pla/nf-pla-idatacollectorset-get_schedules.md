# IDataCollectorSet::get_Schedules

## Description

Retrieves the list of schedules that determine when the data collector set runs.

This property is read-only.

## Parameters

## Remarks

There can be only one instance of a data collector set running at a time; if one is already running and a second one tries to start, the second one will fail and the first one will continue.

To enable the schedules, call the [IDataCollectorSet::SchedulesEnabled](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nf-pla-idatacollectorset-get_schedulesenabled) property.

To manually start the data collector set, call the [IDataCollectorSet::Start](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nf-pla-idatacollectorset-start) method.

## See also

[IDataCollectorSet](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nn-pla-idatacollectorset)

[IDataCollectorSet::SchedulesEnabled](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nf-pla-idatacollectorset-get_schedulesenabled)