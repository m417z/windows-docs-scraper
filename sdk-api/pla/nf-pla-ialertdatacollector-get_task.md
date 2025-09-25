# IAlertDataCollector::get_Task

## Description

Retrieves or sets the name of a Task Scheduler job to start each time the counter value crosses the threshold.

This property is read/write.

## Parameters

## Remarks

To specify command-line arguments for the task, see the [IAlertDataCollector::TaskArguments](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nf-pla-ialertdatacollector-get_taskarguments) and [IAlertDataCollector::TaskUserTextArguments](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nf-pla-ialertdatacollector-get_taskusertextarguments) properties.

To start the task in the directory where PLA is collecting the data, set the task's **Start in** field to $(Arg1).

## See also

[IAlertDataCollector](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nn-pla-ialertdatacollector)