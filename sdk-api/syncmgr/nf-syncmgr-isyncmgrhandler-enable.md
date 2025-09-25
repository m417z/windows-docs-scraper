# ISyncMgrHandler::Enable

## Description

Requests that an [active](https://learn.microsoft.com/windows/desktop/api/syncmgr/nf-syncmgr-isyncmgrhandler-activate) handler be enabled or disabled. An enabled handler can be synchronized and a disabled handler cannot.

## Parameters

### `fEnable` [in]

Type: **BOOL**

**TRUE** to enable; **FALSE** to disable.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

A handler must set the [SYNCMGR_HCM_CAN_ENABLE](https://learn.microsoft.com/windows/desktop/api/syncmgr/ne-syncmgr-syncmgr_handler_capabilities) and [SYNCMGR_HCM_CAN_DISABLE](https://learn.microsoft.com/windows/desktop/api/syncmgr/ne-syncmgr-syncmgr_handler_capabilities) flags for the **Enable** and **Disable** entries to appear on the handler's shortcut menu when the handler is shown in the Sync Center folder. Choosing to enable a handler means that it can be synchronized; choosing to disable a handler means that it cannot.

Sync Center calls this method in the following two instances.

* When the user selects the handler in the Sync Center folder and launches its **Enable** task. If the handler supports the [SYNCMGR_OBJECTID_QueryBeforeEnable](https://learn.microsoft.com/windows/desktop/api/syncmgr/nf-syncmgr-isyncmgrhandler-getobject) object, this method is only called if the UI operation was successful.
* When the user selects the handler in the Sync Center folder and launches its **Disable** task. If the handler supports the [SYNCMGR_OBJECTID_QueryBeforeDisable](https://learn.microsoft.com/windows/desktop/api/syncmgr/nf-syncmgr-isyncmgrhandler-getobject) object, this method is only called if the UI operation was successful.

If the handler does not need to perform any actions when it is activated, it can return either S_OK or E_NOTIMPL as shown in the example below.

#### Examples

The following example shows a simple implementation of this method.

```cpp
STDMETHODIMP CMyDeviceHandler::Enable(__in BOOL fEnable)
{
    return E_NOTIMPL;
}

```

## See also

[ISyncMgrHandler](https://learn.microsoft.com/windows/desktop/api/syncmgr/nn-syncmgr-isyncmgrhandler)

[ISyncMgrHandler::GetObject](https://learn.microsoft.com/windows/desktop/api/syncmgr/nf-syncmgr-isyncmgrhandler-getobject)

[IsEnabled](https://learn.microsoft.com/windows/desktop/api/syncmgr/nf-syncmgr-isyncmgrhandlerinfo-isenabled)