# ISyncMgrHandlerInfo::IsEnabled

## Description

Gets a value that indicates whether the handler is enabled.

## Return value

Type: **HRESULT**

Returns S_OK if the handler is enabled; otherwise, S_FALSE.

If the handler wants Sync Center to maintain the current state, it can return E_NOTIMPL. If any other value is returned, Sync Center sets the handler's enabled state to the last known value and enables or disables the associated tasks as appropriate.

If either the SYNCMGR_HCM_QUERY_BEFORE_ENABLE or SYNCMGR_HCM_QUERY_BEFORE_DISABLE flag is set in the mask returned from [GetCapabilities](https://learn.microsoft.com/windows/desktop/api/syncmgr/nf-syncmgr-isyncmgrhandler-getcapabilities), the handler must manage its own enabled state and therefore must return either S_OK or S_FALSE. Any other return value will be considered an error.

## Remarks

If a handler is disabled, neither it nor any of its items will be synchronized by Sync Center. Also, many of the possible actions available to a handler—such as Sync—are removed or disabled in the Sync Center folder UI.

This value is available in the folder UI as the System.Sync.Enabled (PKEY_Sync_Enabled) property.

Sync Center calls this method whenever the [UpdateHandler](https://learn.microsoft.com/windows/desktop/api/syncmgr/nf-syncmgr-isyncmgrcontrol-updatehandler) method is called.

#### Examples

The following example shows an implementation of this method that calls a private class function to retrieve the enabled state.

```cpp
STDMETHODIMP CMyDeviceHandler::IsEnabled()
{
    // Return a previously-calculated value.
    return (_fIsEnabled ? S_OK : S_FALSE);
}

```

## See also

[Enable](https://learn.microsoft.com/windows/desktop/api/syncmgr/nf-syncmgr-isyncmgrhandler-enable)

[ISyncMgrHandlerInfo](https://learn.microsoft.com/windows/desktop/api/syncmgr/nn-syncmgr-isyncmgrhandlerinfo)