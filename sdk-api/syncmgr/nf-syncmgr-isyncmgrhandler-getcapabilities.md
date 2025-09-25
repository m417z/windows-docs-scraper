# ISyncMgrHandler::GetCapabilities

## Description

Gets a set of flags describing the handler's defined capabilities.

## Parameters

### `pmCapabilities` [out]

Type: **[SYNCMGR_HANDLER_CAPABILITIES](https://learn.microsoft.com/windows/desktop/api/syncmgr/ne-syncmgr-syncmgr_handler_capabilities)***

When this method returns, contains a pointer to a bitwise combination of values from the [SYNCMGR_HANDLER_CAPABILITIES](https://learn.microsoft.com/windows/desktop/api/syncmgr/ne-syncmgr-syncmgr_handler_capabilities) enumeration that defines the capabilities of the handler. Compare against [SYNCMGR_HCM_VALID_MASK](https://learn.microsoft.com/windows/desktop/api/syncmgr/ne-syncmgr-syncmgr_handler_capabilities) to verify a valid value.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This method is called by Sync Center in response to a call to [UpdateHandler](https://learn.microsoft.com/windows/desktop/api/syncmgr/nf-syncmgr-isyncmgrcontrol-updatehandler) or [UpdateHandlerCollection](https://learn.microsoft.com/windows/desktop/api/syncmgr/nf-syncmgr-isyncmgrcontrol-updatehandlercollection).

#### Examples

The following example shows an implementation of this method.

```cpp
STDMETHODIMP CMyDeviceHandler::GetCapabilities(
                             __out SYNCMGR_HANDLER_CAPABILITIES *pmCapabilities)
{
    *pmCapabilities = SYNCMGR_HCM_EVENT_STORE
                    | SYNCMGR_HCM_QUERY_BEFORE_ACTIVATE;
    return S_OK;
}

```