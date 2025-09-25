# ITaskFolder::GetTask

## Description

Gets a task at a specified location in a folder.

## Parameters

### `path` [in]

The path (location) to the task in a folder. The root task folder is specified with a backslash (\\). An example of a task folder path, under the root task folder,
is \MyTaskFolder. The '.' character cannot be used to specify the current task folder and the '..' characters cannot be used to specify the parent task folder in the path.

### `ppTask` [out]

The task at the specified location.

Pass in a reference to a **NULL** [IRegisteredTask](https://learn.microsoft.com/windows/desktop/api/taskschd/nn-taskschd-iregisteredtask) interface pointer. Referencing a non-**NULL** pointer can cause a memory leak because the pointer will be overwritten.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[ITaskFolder](https://learn.microsoft.com/windows/desktop/api/taskschd/nn-taskschd-itaskfolder)