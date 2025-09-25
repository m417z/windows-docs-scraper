# ITaskFolder::DeleteFolder

## Description

Deletes a subfolder from the parent folder.

## Parameters

### `subFolderName` [in]

The name of the subfolder to be removed. The root task folder is specified with a backslash (\\). This parameter can be a relative path to the folder you want to delete. An example of a task folder path, under the root task folder,
is \MyTaskFolder. The '.' character cannot be used to specify the current task folder and the '..' characters cannot be used to specify the parent task folder in the path.

### `flags` [in]

Not supported.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[ITaskFolder](https://learn.microsoft.com/windows/desktop/api/taskschd/nn-taskschd-itaskfolder)

[Task Scheduler](https://learn.microsoft.com/windows/desktop/TaskSchd/task-scheduler-start-page)