# IAlertDataCollector::put_AlertThresholds

## Description

Retrieves or sets a list of performance counters and thresholds to monitor.

This property is read/write.

## Parameters

## Remarks

You must specify at least one alert threshold. If the counter value crosses the specified threshold value, PLA performs one or more of the following actions:

* Logs event 2031 to the Microsoft-Windows-Diagnosis-PLA/Operational event log if the [IAlertDataCollector::EventLog](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nf-pla-ialertdatacollector-get_eventlog) property is true.
* Starts the task in the [IAlertDataCollector::Task](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nf-pla-ialertdatacollector-get_task) property, if specified.
* Triggers the data collector set specified in the [IAlertDataCollector::TriggerDataCollectorSet](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nf-pla-ialertdatacollector-get_triggerdatacollectorset) property to run, if specified.

If you use XML to define the alert, you must use "&gt;" for the greater than sign (>) and "&lt;" for the less than sign (<).

## See also

[IAlertDataCollector](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nn-pla-ialertdatacollector)