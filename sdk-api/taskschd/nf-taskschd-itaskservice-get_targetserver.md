# ITaskService::get_TargetServer

## Description

Gets the name of the computer that is running the Task Scheduler service that the user is connected to.

This property is read-only.

## Parameters

## Remarks

This property returns an empty string when the user passes an IP address, Localhost, or '.' into the *pServer* parameter, and it returns the name of the computer that is running the Task Scheduler service when the user does not pass any parameter value.

## See also

[ITaskService](https://learn.microsoft.com/windows/desktop/api/taskschd/nn-taskschd-itaskservice)