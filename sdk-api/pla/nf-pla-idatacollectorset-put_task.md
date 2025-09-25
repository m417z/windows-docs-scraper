# IDataCollectorSet::put_Task

## Description

Retrieves or sets the name of a [Task Scheduler](https://learn.microsoft.com/windows/desktop/TaskSchd/task-scheduler-start-page) job to start each time the data collector set stops, including between segments.

This property is read/write.

## Parameters

## Remarks

To specify command-line arguments for the task, see [IDataCollectorSet::TaskArguments](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nf-pla-idatacollectorset-get_taskarguments) and [IDataCollectorSet::TaskUserTextArguments](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nf-pla-idatacollectorset-get_taskusertextarguments).

To start the task in the directory where PLA is collecting the data, set the task's **Start in** field to $(Arg1).

## See also

[IDataCollectorSet](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nn-pla-idatacollectorset)

[IDataCollectorSet::TaskArguments](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nf-pla-idatacollectorset-get_taskarguments)

[IDataCollectorSet::TaskUserTextArguments](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nf-pla-idatacollectorset-get_taskusertextarguments)