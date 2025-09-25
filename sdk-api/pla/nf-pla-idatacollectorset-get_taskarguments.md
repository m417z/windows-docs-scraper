# IDataCollectorSet::get_TaskArguments

## Description

Retrieves or sets the command-line arguments to pass to the [Task Scheduler](https://learn.microsoft.com/windows/desktop/TaskSchd/task-scheduler-start-page) job specified in the [IDataCollectorSet::Task](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nf-pla-idatacollectorset-get_task) property.

This property is read/write.

## Parameters

## Remarks

PLA provides the following substitution variables that you can include in your arguments string. PLA provides the values for the substitution variables when the task is triggered. You must escape the braces, for example, \{name\}.

| Variable | Description |
| --- | --- |
| {key} | Space-delimited list of key values that were specified using the [IDataCollectorSet::SetValue](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nf-pla-idatacollectorset-setvalue) method. |
| {logs} | Space-delimited list of full paths to the current data collector files. |
| {state} | Indicates whether the set is running (1 for running, 0 for stopped). |
| {usertext} | String from the [IDataCollectorSet::TaskUserTextArguments](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nf-pla-idatacollectorset-get_taskusertextarguments) property. |

Typically, if you use the substitution variables, you specify them in [TaskUserTextArguments](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nf-pla-idatacollectorset-get_taskusertextarguments), where you do not have to escape the braces and then specify {usertext} in this property.

## See also

[IDataCollectorSet](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nn-pla-idatacollectorset)

[IDataCollectorSet::Task](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nf-pla-idatacollectorset-get_task)

[IDataCollectorSet::TaskUserTextArguments](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nf-pla-idatacollectorset-get_taskusertextarguments)