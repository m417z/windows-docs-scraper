# ITaskFolder::GetFolder

## Description

Gets a folder that contains tasks at a specified location.

## Parameters

### `path` [in]

The path (location) to the folder. Do not use a backslash following the last folder name in the path. The root task folder is specified with a backslash (\\). An example of a task folder path, under the root task folder,
is \MyTaskFolder. The '.' character cannot be used to specify the current task folder and the '..' characters cannot be used to specify the parent task folder in the path.

### `ppFolder` [out]

The folder at the specified location.

Pass in a reference to a **NULL** [ITaskFolder](https://learn.microsoft.com/windows/desktop/api/taskschd/nn-taskschd-itaskfolder) interface pointer. Referencing a non-**NULL** pointer can cause a memory leak because the pointer will be overwritten.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[ITaskFolder](https://learn.microsoft.com/windows/desktop/api/taskschd/nn-taskschd-itaskfolder)