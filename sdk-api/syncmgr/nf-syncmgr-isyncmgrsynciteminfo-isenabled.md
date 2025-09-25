# ISyncMgrSyncItemInfo::IsEnabled

## Description

Generates a value that indicates whether the item is enabled.

## Return value

Type: **HRESULT**

Returns S_OK if the item is enabled; otherwise, S_FALSE.

If the item wants Sync Center to maintain the current state, it can return E_NOTIMPL. If any other value is returned, Sync Center sets the item's enabled state to the last known value and enables or disables the associated tasks as appropriate.

If either the SYNCMGR_ICM_QUERY_BEFORE_ENABLE or SYNCMGR_ICM_QUERY_BEFORE_DISABLE flags are set in the mask returned from [GetCapabilities](https://learn.microsoft.com/windows/desktop/api/syncmgr/nf-syncmgr-isyncmgrsyncitem-getcapabilities), the handler must manage its own enabled state and therefore must return either S_OK or S_FALSE. Any other return value will be considered an error.

## Remarks

If an item is disabled, it is not synchronized by Sync Center. Also, many of the possible actions available to an item—such as Sync—are removed or disabled in the UI.

An item can implement a [Disconnected](https://learn.microsoft.com/windows/desktop/api/syncmgr/nf-syncmgr-isyncmgrsynciteminfo-isconnected) state by returning S_FALSE from **IsEnabled** and setting the SYNCMR_IPM_PREVENT_ENABLE flag in its [GetPolicies](https://learn.microsoft.com/windows/desktop/api/syncmgr/nf-syncmgr-isyncmgrsyncitem-getpolicies) implementation. This shows the item as disabled and prevents the user from enabling it manually.

The enabled value is available in the folder UI as the System.Sync.Enabled (PKEY_Sync_Enabled) property.

Sync Center calls this method whenever the [UpdateHandler](https://learn.microsoft.com/windows/desktop/api/syncmgr/nf-syncmgr-isyncmgrcontrol-updatehandler) method is called.

#### Examples

The following example shows an implementation of this method that calls a private class function to retrieve the enabled state.

```cpp
STDMETHODIMP CMyDeviceSyncItem::IsEnabled()
{
    // Return a previously-calculated value.
    return (_fIsEnabled ? S_OK : S_FALSE);
}

```