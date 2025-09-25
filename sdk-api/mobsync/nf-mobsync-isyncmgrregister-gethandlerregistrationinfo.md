# ISyncMgrRegister::GetHandlerRegistrationInfo

## Description

Called by the registered application's handler to get current registration information.

## Parameters

### `clsidHandler` [in]

Type: **REFCLSID**

The CLSID of the handler.

### `pdwSyncMgrRegisterFlags` [in, out]

Type: **LPDWORD**

Returns registration flags from the [SYNCMGRREGISTERFLAGS](https://learn.microsoft.com/windows/desktop/api/mobsync/ne-mobsync-syncmgrregisterflags) enumeration that indicate events for which the handler is registered to be notified.

## Return value

Type: **HRESULT**

This method supports the standard return values E_INVALIDARG, E_UNEXPECTED, and E_OUTOFMEMORY, as well as the following:

| Return code | Description |
| --- | --- |
| **S_OK** | Call was successful, the handler is registered. |
| **S_FALSE** | Call was not successful, the handler is not registered. |

## See also

[ISyncMgrRegister](https://learn.microsoft.com/windows/desktop/api/mobsync/nn-mobsync-isyncmgrregister)