# IOfflineFilesProgress::End

## Description

Reports that an operation has ended.

## Parameters

### `hrResult` [in]

Indicates the result of the operation as a whole. Contains S_OK if the operation completed successfully, HRESULT_FROM_WIN32(ERROR_CANCELLED) if the operation was canceled or an error value otherwise.

## Return value

The return value is ignored.

## See also

[IOfflineFilesProgress](https://learn.microsoft.com/previous-versions/windows/desktop/api/cscobj/nn-cscobj-iofflinefilesprogress)