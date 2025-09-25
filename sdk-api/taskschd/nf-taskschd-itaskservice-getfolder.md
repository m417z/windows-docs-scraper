# ITaskService::GetFolder

## Description

Gets a folder of registered tasks.

## Parameters

### `path` [in]

The path to the folder to retrieve. Do not use a backslash following the last folder name in the path. The root task folder is specified with a backslash (\\). An example of a task folder path, under the root task folder,
is \MyTaskFolder. The '.' character cannot be used to specify the current task folder and the '..' characters cannot be used to specify the parent task folder in the path.

### `ppFolder` [out]

An [ITaskFolder](https://learn.microsoft.com/windows/desktop/api/taskschd/nn-taskschd-itaskfolder) interface for the requested folder.

Pass in a reference to a **NULL** [ITaskFolder](https://learn.microsoft.com/windows/desktop/api/taskschd/nn-taskschd-itaskfolder) interface pointer. Referencing a non-**NULL** pointer can cause a memory leak because the pointer will be overwritten.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[ITaskService](https://learn.microsoft.com/windows/desktop/api/taskschd/nn-taskschd-itaskservice)

[Task Scheduler](https://learn.microsoft.com/windows/desktop/TaskSchd/task-scheduler-start-page)