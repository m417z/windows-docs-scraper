# ITaskScheduler::IsOfType

## Description

[[This API may be altered or unavailable in subsequent versions of the operating system or product. Please use the [Task Scheduler 2.0 Interfaces](https://learn.microsoft.com/windows/desktop/TaskSchd/task-scheduler-2-0-interfaces) instead.] ]

The
**IsOfType** method checks the object's type to verify that it supports a particular interface.

## Parameters

### `pwszName` [in]

A null-terminated string that contains the name of the object to check.

### `riid` [in]

The reference identifier of the interface to be matched.

## Return value

The
**IsOfType** method returns S_OK if the object named by *pwszName* supports the interface specified in *riid*. Otherwise, S_FALSE is returned.

## See also

[ITaskScheduler](https://learn.microsoft.com/windows/desktop/api/mstask/nn-mstask-itaskscheduler)