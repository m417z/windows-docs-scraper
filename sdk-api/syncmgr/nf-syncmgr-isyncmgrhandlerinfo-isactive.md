# ISyncMgrHandlerInfo::IsActive

## Description

Gets a value that indicates whether the handler can be synchronized.

## Return value

Type: **HRESULT**

Returns S_OK if the handler is active; otherwise, S_FALSE.

If the handler wants Sync Center to maintain the current state, it can return E_NOTIMPL. If any other value is returned, Sync Center sets the handler's state to the last known value. If the handler's last known value in that situation was inactive, Sync Center disables the **Setup** task. If the handler's last known value was active, the **Delete** task is not disabled.

If either the SYNCMGR_HCM_QUERY_BEFORE_ACTIVATE or SYNCMGR_HCM_QUERY_BEFORE_DEACTIVE flag is set in the mask returned from [GetCapabilities](https://learn.microsoft.com/windows/desktop/api/syncmgr/nf-syncmgr-isyncmgrhandler-getcapabilities), the handler must manage its own activation state and therefore must return either S_OK or S_FALSE. Any other return value will be considered an error.

## Remarks

If a handler is not active, it appears in the Sync Setup folder. Handlers in that folder cannot be synchronized. To move a handler to the Sync Center folder, the user selects the **Setup** task on the handler's shortcut menu or from the command module.

If a handler is active it appears in the main Sync Center folder. A handler that is active can be synchronized either by the user or through the [ISyncMgrControl](https://learn.microsoft.com/windows/desktop/api/syncmgr/nn-syncmgr-isyncmgrcontrol) interface. To move a handler to the Sync Setup folder, the user selects the **Delete** task on the handler's shortcut menu or on the command module.

Sync Center calls this method whenever the [UpdateHandler](https://learn.microsoft.com/windows/desktop/api/syncmgr/nf-syncmgr-isyncmgrcontrol-updatehandler) method is called.

#### Examples

The following example shows an implementation of this method that calls a private class function to retrieve the active state.

```cpp
STDMETHODIMP CMyDeviceHandler::IsActive()
{
    // Return a previously-calculated value.
    return (_fIsActive ? S_OK : S_FALSE);
}

```

## See also

[Activate](https://learn.microsoft.com/windows/desktop/api/syncmgr/nf-syncmgr-isyncmgrhandler-activate)

[ISyncMgrHandlerInfo](https://learn.microsoft.com/windows/desktop/api/syncmgr/nn-syncmgr-isyncmgrhandlerinfo)