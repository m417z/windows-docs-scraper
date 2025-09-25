# ISyncMgrHandler::GetHandlerInfo

## Description

Gets properties that describe the handler.

## Parameters

### `ppHandlerInfo` [out]

Type: **[ISyncMgrHandlerInfo](https://learn.microsoft.com/windows/desktop/api/syncmgr/nn-syncmgr-isyncmgrhandlerinfo)****

When this method returns, contains the address of a pointer to an instance of the [ISyncMgrHandlerInfo](https://learn.microsoft.com/windows/desktop/api/syncmgr/nn-syncmgr-isyncmgrhandlerinfo) interface that provides access to the handler properties.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

If this method fails, the handler is still shown in the Sync Center folder and Sync Center continues to invoke it, but default values are used for all properties.

**ISyncMgrHandler::GetHandlerInfo**, together with [ISyncMgrHandler::GetName](https://learn.microsoft.com/windows/desktop/api/syncmgr/nf-syncmgr-isyncmgrhandler-getname), replaces the older [GetHandlerInfo](https://learn.microsoft.com/windows/desktop/api/mobsync/nf-mobsync-isyncmgrsynchronize-gethandlerinfo).

#### Examples

The following example shows an implementation of this method.

```cpp
STDMETHODIMP CMyDeviceHandler::GetHandlerInfo(
                             __out ISyncMgrHandlerInfo **ppHandlerInfo)
{
    *ppHandlerInfo = NULL;
    HRESULT hr = QueryInterface(IID_ISyncMgrHandlerInfo,
                                (void **) ppHandlerInfo);
    return hr;
}

```