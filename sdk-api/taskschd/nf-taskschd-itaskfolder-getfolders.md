# ITaskFolder::GetFolders

## Description

Gets all the subfolders in the folder.

## Parameters

### `flags` [in]

This parameter is reserved for future use and must be set to 0.

### `ppFolders` [out]

The collection of subfolders in the folder.

Pass in a reference to a **NULL** [ITaskFolderCollection](https://learn.microsoft.com/windows/desktop/api/taskschd/nn-taskschd-itaskfoldercollection) interface pointer. Referencing a non-**NULL** pointer can cause a memory leak because the pointer will be overwritten.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[ITaskFolder](https://learn.microsoft.com/windows/desktop/api/taskschd/nn-taskschd-itaskfolder)

[Task Scheduler](https://learn.microsoft.com/windows/desktop/TaskSchd/task-scheduler-start-page)