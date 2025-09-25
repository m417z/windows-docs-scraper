# IAlertDataCollector::get_TaskUserTextArguments

## Description

Retrieves or sets the command-line arguments to pass to the Task Scheduler job specified in the [IAlertDataCollector::Task](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nf-pla-ialertdatacollector-get_task) property.

This property is read/write.

## Parameters

## Remarks

These arguments are included in the command-line arguments passed to the Task Scheduler job only if the [IAlertDataCollector::TaskArguments](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nf-pla-ialertdatacollector-get_taskarguments) property includes the {usertext} substitution variable.

PLA provides the following substitution variables that you can include in your arguments string. PLA provides the values for the substitution variables when the alert is triggered. You do not escape the braces.

| Variable | Description |
| --- | --- |
| {counter} | Path of the performance counter that crossed the threshold. |
| {date} | Time that the threshold was crossed. |
| {name} | Name of the alert data collector. |
| {threshold} | Value of the threshold. |
| {value} | Value of the performance counter. |

## See also

[IAlertDataCollector](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nn-pla-ialertdatacollector)