# ISyncMgrRegister::UnregisterSyncMgrHandler

## Description

Removes a handler's class identifier (CLSID) from the registration. A handler should call this when it no longer has any items to synchronize.

## Parameters

### `clsidHandler` [in]

Type: **REFCLSID**

The CLSID of the handler that should be unregistered.

### `dwReserved` [in]

Type: **DWORD**

## Return value

Type: **HRESULT**

This method supports the standard return values E_INVALIDARG, E_UNEXPECTED, and E_OUTOFMEMORY, as well as the following:

| Return code | Description |
| --- | --- |
| **S_OK** | The handler was successfully removed from the registry with SyncMgr. |

## See also

[ISyncMgrRegister](https://learn.microsoft.com/windows/desktop/api/mobsync/nn-mobsync-isyncmgrregister)