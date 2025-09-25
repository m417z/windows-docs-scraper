# ITaskFolder::CreateFolder

## Description

Creates a folder for related tasks.

## Parameters

### `subFolderName` [in]

The name used to identify the folder. If "FolderName\SubFolder1\SubFolder2" is specified, the entire folder tree will be created if the folders do not exist. This parameter can be a relative path to the current [ITaskFolder](https://learn.microsoft.com/windows/desktop/api/taskschd/nn-taskschd-itaskfolder) instance. The root task folder is specified with a backslash (\\). An example of a task folder path, under the root task folder,
is \MyTaskFolder. The '.' character cannot be used to specify the current task folder and the '..' characters cannot be used to specify the parent task folder in the path.

### `sddl` [in]

The security descriptor associated with the folder, in the form of a VT_BSTR in SDDL_REVISION_1 format.

### `ppFolder` [out]

An [ITaskFolder](https://learn.microsoft.com/windows/desktop/api/taskschd/nn-taskschd-itaskfolder) interface that represents the new subfolder.

Pass in a reference to a **NULL** [ITaskFolder](https://learn.microsoft.com/windows/desktop/api/taskschd/nn-taskschd-itaskfolder) interface pointer. Referencing a non-**NULL** pointer can cause a memory leak because the pointer will be overwritten.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

To retrieve the subfolders of the parent folder, use the [GetFolders](https://learn.microsoft.com/windows/desktop/api/taskschd/nf-taskschd-itaskfolder-getfolders) method.

The **CreateFolder** method will return 0x800700b7 if the folder that you are trying to create already exists.

Specifying an invalid security descriptor in the *sddl* parameter will cause this method to return **E_INVALIDARG**.

## See also

[ITaskFolder](https://learn.microsoft.com/windows/desktop/api/taskschd/nn-taskschd-itaskfolder)

[Task Scheduler](https://learn.microsoft.com/windows/desktop/TaskSchd/task-scheduler-start-page)