# ISyncMgrRegister::RegisterSyncMgrHandler

## Description

Registers a handler with the synchronization manager when the handler has items to synchronize.

## Parameters

### `clsidHandler` [in]

Type: **REFCLSID**

The CLSID of the handler that should be registered to do synchronizations.

### `pwszDescription` [in]

Type: **LPCWSTR**

Text identifying the handler. This parameter may be **NULL**.

### `dwSyncMgrRegisterFlags` [in]

Type: **DWORD**

## Return value

Type: **HRESULT**

This method supports the standard return values E_INVALIDARG, E_UNEXPECTED, and E_OUTOFMEMORY, as well as the following:

| Return code | Description |
| --- | --- |
| **S_OK** | The handler was successfully registered. |

## See also

[ISyncMgrRegister](https://learn.microsoft.com/windows/desktop/api/mobsync/nn-mobsync-isyncmgrregister)