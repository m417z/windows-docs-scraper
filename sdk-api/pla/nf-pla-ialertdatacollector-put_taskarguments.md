# IAlertDataCollector::put_TaskArguments

## Description

Retrieves or sets the command-line arguments to pass to the Task Scheduler job specified in the [IAlertDataCollector::Task](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nf-pla-ialertdatacollector-get_task) property.

This property is read/write.

## Parameters

## Remarks

If the task to run is a script, you must set the task arguments in the Task Scheduler to $(Arg0); otherwise, the arguments that you specify with this property will not be passed to the script.

PLA provides the following substitution variables that you can include in your arguments string. PLA provides the values for the substitution variables when the alert is triggered. You must escape the braces, for example, \{name\}.

| Variable | Description |
| --- | --- |
| {counter} | Path of the performance counter that crossed the threshold. |
| {date} | Time that the threshold was crossed. |
| {name} | Name of the alert data collector. |
| {threshold} | Value of the threshold. |
| {usertext} | String from the [IAlertDataCollector::TaskUserTextArguments](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nf-pla-ialertdatacollector-get_taskusertextarguments) property. |
| {value} | Value of the performance counter. |

Typically, if you use the substitution variables, you specify them in [TaskUserTextArguments](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nf-pla-ialertdatacollector-get_taskusertextarguments), where you do not have to escape the braces, and then specify {usertext} in this property.

## See also

[IAlertDataCollector](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nn-pla-ialertdatacollector)