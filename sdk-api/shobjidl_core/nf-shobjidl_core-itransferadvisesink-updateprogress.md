# ITransferAdviseSink::UpdateProgress

## Description

Updates the transfer progress status in the UI.

## Parameters

### `ullSizeCurrent` [in]

Type: **ULONGLONG**

The number of bytes processed in the current operation.

### `ullSizeTotal` [in]

Type: **ULONGLONG**

The total number of bytes in the current operation.

### `nFilesCurrent` [in]

Type: **int**

The number of files processed in the current operation.

### `nFilesTotal` [in]

Type: **int**

The total number of files in the operation. Set to 0 to indicate that the value has not changed since the last call to this method.

### `nFoldersCurrent` [in]

Type: **int**

The number of folders processed in the current operation.

### `nFoldersTotal` [in]

Type: **int**

The total number of folders in the operation. Set to 0 to indicate that the value has not changed since the last call to this method.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Set *ullSizeTotal*, *nFilesTotal*, and *nFoldersTotal* all to 0 to indicate that the totals have not changed since the last call to this method.

Set all six parameters to 0 to indicate that progress has not changed since the last call to this method.

### Note to Implementers

Implementers of this function should return an error code when the operation needs to terminate before it is complete, such as when the user clicks the **Cancel** button.