# IPrincipal2::AddRequiredPrivilege

## Description

Adds the required privilege to the task process token.

## Parameters

### `privilege` [in]

Specifies the right of a task to perform various system-related operations, such as shutting down the system, loading device drivers, or changing the system time.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IPrincipal2](https://learn.microsoft.com/windows/desktop/api/taskschd/nn-taskschd-iprincipal2)

[Task Scheduler](https://learn.microsoft.com/windows/desktop/TaskSchd/task-scheduler-start-page)