# IFileSyncMergeHandler::Merge

## Description

Merges changes between the local copy and server copy of a file.

## Parameters

### `localFilePath` [in]

Type: **LPCWSTR**

A pointer to a string containing the path to the local copy of the file.

### `serverFilePath` [in]

Type: **LPCWSTR**

A pointer to a string containing the network path to the server copy of the file.

### `updateStatus` [out]

Type: **MERGE_UPDATE_STATUS***

When this method returns, contains a pointer to one of the following values indicating status of the merge process.

#### MUS_COMPLETE

Indicates that the process has completed successfully.

#### MUS_USERINPUTNEEDED

Indicates that additional input is required by the user for the process to complete.

#### MUS_FAILED

Indicates that the process has failed.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IFileSyncMergeHandler](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ifilesyncmergehandler)