# ISyncMgrHandler::Activate

## Description

Requests that the handler is activated or deactivated. An active handler can be synchronized; an inactive handler cannot.

## Parameters

### `fActivate` [in]

Type: **BOOL**

**TRUE** to activate; **FALSE** to deactivate.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

An active handler appears in the Sync Center folder and can be synchronized. An inactive handler appears in the Sync Setup folder and must be activated (which moves it to the Sync Center folder) before it can be synchronized.

The activation state should not be confused with the enabled state. An active handler can be disabled. This means that it is still shown in the Sync Center folder but that it cannot be synchronized.

Sync Center calls this method in the following two instances.

* When the user selects the handler in the Sync Setup folder and launches its **Setup** task. If the handler supports the [SYNCMGR_OBJECTID_QueryBeforeActivate](https://learn.microsoft.com/windows/desktop/api/syncmgr/nf-syncmgr-isyncmgrhandler-getobject) object, this method is only called if the UI operation, which consists of a dialog asking the user to confirm whether they want to activate the handler, was successful.
* When the user selects the handler in the Sync Center folder and launches its **Delete** task, but only if the handler has not set the [SYNCMGR_HPM_PREVENT_DEACTIVATE](https://learn.microsoft.com/windows/desktop/api/syncmgr/ne-syncmgr-syncmgr_handler_policies) flag. If the handler supports the [SYNCMGR_OBJECTID_QueryBeforeDeactivate](https://learn.microsoft.com/windows/desktop/api/syncmgr/nf-syncmgr-isyncmgrhandler-getobject) object, this method is only called if the UI operation was successful.

If the [SYNCMGR_HPM_PREVENT_ACTIVATE](https://learn.microsoft.com/windows/desktop/api/syncmgr/ne-syncmgr-syncmgr_handler_policies) flag is set in the value retrieved by [ISyncMgrHandler::GetCapabilities](https://learn.microsoft.com/windows/desktop/api/syncmgr/nf-syncmgr-isyncmgrhandler-getcapabilities), a call to this method requesting activation of the handler will fail.

The activation state of an individual handler can be found by calling [IsActive](https://learn.microsoft.com/windows/desktop/api/syncmgr/nf-syncmgr-isyncmgrhandlerinfo-isactive).

If the handler does not need to perform any actions when it is activated, it can return either S_OK or E_NOTIMPL as shown in the example below.

#### Examples

The following example shows a simple implementation of this method.

```cpp
STDMETHODIMP CMyDeviceHandler::Activate(__in BOOL fActivate)
{
    return E_NOTIMPL;
}

```

## See also

[ISyncMgrHandler](https://learn.microsoft.com/windows/desktop/api/syncmgr/nn-syncmgr-isyncmgrhandler)

[ISyncMgrHandler::GetObject](https://learn.microsoft.com/windows/desktop/api/syncmgr/nf-syncmgr-isyncmgrhandler-getobject)

[ISyncMgrUIOperation::Run](https://learn.microsoft.com/windows/desktop/api/syncmgr/nf-syncmgr-isyncmgruioperation-run)