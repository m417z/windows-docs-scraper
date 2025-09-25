# IRegisteredTask::Run

## Description

Runs the registered task immediately.

## Parameters

### `params` [in]

The parameters used as values in the task actions. To not specify any parameter values for the task actions, set this parameter to **VT_NULL** or **VT_EMPTY**. Otherwise, a single **BSTR** value or an array of **BSTR** values can be specified.

The **BSTR** values that you specify are paired with names and stored as name-value pairs. If you specify a single **BSTR** value, then Arg0 will be the name assigned to the value. The value can be used in the task action where the $(Arg0) variable is used in the action properties.

If you pass in values such as "0", "100", and "250" as an array of **BSTR** values, then "0" will replace the $(Arg0) variables, "100" will replace the $(Arg1) variables, and "250" will replace the $(Arg2) variables that are used in the action properties.

A maximum of 32 **BSTR** values can be specified.

For more information and a list of action properties that can use $(Arg0), $(Arg1), ..., $(Arg32) variables in their values, see [Task Actions](https://learn.microsoft.com/windows/desktop/TaskSchd/task-actions).

### `ppRunningTask` [out, optional]

An [IRunningTask](https://learn.microsoft.com/windows/desktop/api/taskschd/nn-taskschd-irunningtask) interface that defines the new instance of the task.

Pass in a reference to a **NULL** [IRunningTask](https://learn.microsoft.com/windows/desktop/api/taskschd/nn-taskschd-irunningtask) interface pointer. Referencing a non-**NULL** pointer can cause a memory leak because the pointer will be overwritten.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This method will return without error, but the task will not run if the [AllowDemandStart](https://learn.microsoft.com/windows/desktop/api/taskschd/nf-taskschd-itasksettings-get_allowdemandstart) property of ITaskSettings is set to false for the task.

The **IRegisteredTask::Run** function is equivalent to the [IRegisteredTask::RunEx](https://learn.microsoft.com/windows/desktop/api/taskschd/nf-taskschd-iregisteredtask-runex) function with the flags parameter equal to 0 and the user parameter equal to **NULL**.

If **IRegisteredTask::Run** is invoked from a disabled task, it will return SCHED_E_TASK_DISABLED.

## See also

[IRegisteredTask](https://learn.microsoft.com/windows/desktop/api/taskschd/nn-taskschd-iregisteredtask)

[Task Scheduler](https://learn.microsoft.com/windows/desktop/TaskSchd/task-scheduler-start-page)