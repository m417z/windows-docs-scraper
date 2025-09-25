# ITaskFolder::DeleteTask

## Description

Deletes a task from the folder.

## Parameters

### `name` [in]

The name of the task that is specified when the task was registered. The '.' character cannot be used to specify the current task folder and the '..' characters cannot be used to specify the parent task folder in the path.

### `flags` [in]

Not supported.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[ITaskFolder](https://learn.microsoft.com/windows/desktop/api/taskschd/nn-taskschd-itaskfolder)

[Task Scheduler](https://learn.microsoft.com/windows/desktop/TaskSchd/task-scheduler-start-page)