# ISyncMgrSyncItemInfo::IsConnected

## Description

Generates a value that indicates whether the item—typically some type of external device—is connected.

## Return value

Type: **HRESULT**

Returns S_OK if the item is connected; otherwise, S_FALSE. An error returned by this method will be interpreted as S_OK.

## Remarks

If an item is disconnected, it is not synchronized by Sync Center. Also, many of the possible actions available to a item—such as Sync—are removed or disabled in the UI.

This value is available in the folder UI as the System.Sync.Connected (PKEY_Sync_Connected) property.

Sync Center calls this method whenever the [UpdateHandler](https://learn.microsoft.com/windows/desktop/api/syncmgr/nf-syncmgr-isyncmgrcontrol-updatehandler) method is called.

#### Examples

The following example shows an implementation of this method that calls a private class function to retrieve the connected state.

```cpp
STDMETHODIMP CMyDeviceSyncItem::IsConnected()
{
    return (_IsConnected() ? S_OK : S_FALSE);
}

```