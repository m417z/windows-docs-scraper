# ISyncMgrHandlerInfo::GetType

## Description

Gets the handler type for Sync Center.

## Parameters

### `pnType` [out]

Type: **[SYNCMGR_HANDLER_TYPE](https://learn.microsoft.com/windows/desktop/api/syncmgr/ne-syncmgr-syncmgr_handler_type)***

When this method returns, points to a value from the [SYNCMGR_HANDLER_TYPE](https://learn.microsoft.com/windows/desktop/api/syncmgr/ne-syncmgr-syncmgr_handler_type) enumeration that specifies the handler type. If the method fails, this parameter points to [SYNCMGR_HT_UNSPECIFIED](https://learn.microsoft.com/windows/desktop/api/syncmgr/ne-syncmgr-syncmgr_handler_type).

## Return value

Type: **HRESULT**

Returns S_OK if successful, or an error value otherwise. If the method fails, *pnType* is set to [SYNCMGR_HT_UNSPECIFIED](https://learn.microsoft.com/windows/desktop/api/syncmgr/ne-syncmgr-syncmgr_handler_type).

## Remarks

Typically, this value does not change. However, Sync Center calls this method whenever the [UpdateHandler](https://learn.microsoft.com/windows/desktop/api/syncmgr/nf-syncmgr-isyncmgrcontrol-updatehandler) method is called.

#### Examples

The following example shows an implementation of this method.

```cpp
STDMETHODIMP CMyDeviceHandler::GetType(__out SYNCMGR_HANDLER_TYPE *pnType)
{
    *pnType = SYNCMGR_HT_DEVICE;
    return S_OK;

```