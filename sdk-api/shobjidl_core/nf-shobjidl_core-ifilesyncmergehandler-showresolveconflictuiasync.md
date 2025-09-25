# IFileSyncMergeHandler::ShowResolveConflictUIAsync

## Description

Displays a UI to resolve conflicts between the local copy and server copy of a file.

## Parameters

### `localFilePath` [in]

Type: **LPCWSTR**

The path of the file with the merge conflict.

### `monitorToDisplayOn` [in]

Type: **HMONITOR**

Indicates the monitor on which to display the UI.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IFileSyncMergeHandler](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ifilesyncmergehandler)