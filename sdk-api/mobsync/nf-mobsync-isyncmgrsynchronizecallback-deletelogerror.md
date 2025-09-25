# ISyncMgrSynchronizeCallback::DeleteLogError

## Description

Called by the registered application's handler to delete a previously logged ErrorInformation, warning, or error message in the error tab on the synchronization manager status dialog box.

## Parameters

### `ErrorID` [in]

Type: **REFGUID**

The LogError to be deleted. If *ErrorID* is GUID_NULL all errors logged by the instance of the registered application's handler will be deleted.

### `dwReserved` [in]

Type: **DWORD**

## Return value

Type: **HRESULT**

This method supports the standard return values E_INVALIDARG, E_UNEXPECTED, and E_OUTOFMEMORY, as well as the following:

| Return code | Description |
| --- | --- |
| **S_OK** | The item was successfully deleted from the log. |

## See also

[ISyncMgrSynchronizeCallback](https://learn.microsoft.com/windows/desktop/api/mobsync/nn-mobsync-isyncmgrsynchronizecallback)