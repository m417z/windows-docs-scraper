# IDataCollectorSet::put_TaskUserTextArguments

## Description

Retrieves or sets the command-line arguments that are substituted for the {usertext} substitution variable in the [IDataCollectorSet::TaskArguments](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nf-pla-idatacollectorset-get_taskarguments) property.

This property is read/write.

## Parameters

## Remarks

These arguments are included in the command-line arguments passed to the Task Scheduler job only if the [TaskArguments](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nf-pla-idatacollectorset-get_taskarguments) property includes the {usertext} substitution variable.

PLA provides the following substitution variables that you can include in your arguments string. PLA provides the values for the substitution variables when the task is triggered. You do not escape the braces.

| Variable | Description |
| --- | --- |
| {key} | Space-delimited list of key values that were specified using the [IDataCollectorSet::SetValue](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nf-pla-idatacollectorset-setvalue) method. |
| {logs} | Space-delimited list of full paths to the current data collector files. |
| {state} | Indicates whether the set is running (1 for running, 0 for stopped). |

## See also

[IDataCollectorSet](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nn-pla-idatacollectorset)

[IDataCollectorSet::TaskArguments](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nf-pla-idatacollectorset-get_taskarguments)