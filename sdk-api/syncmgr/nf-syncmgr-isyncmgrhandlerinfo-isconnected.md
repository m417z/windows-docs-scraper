# ISyncMgrHandlerInfo::IsConnected

## Description

Gets a value that indicates whether the handler—typically some type of external device—is connected.

## Return value

Type: **HRESULT**

Returns S_OK if the handler is connected; otherwise, S_FALSE. An error returned by this method will be interpreted as S_OK.

## Remarks

If a handler is disconnected, neither it nor any of its items will be synchronized by Sync Center. Also, many of the possible actions available to a handler—such as Sync—are removed or disabled in the Sync Center folder UI.

This value is available in the folder UI as the System.Sync.Connected (PKEY_Sync_Connected) property.

Sync Center calls this method whenever the [UpdateHandler](https://learn.microsoft.com/windows/desktop/api/syncmgr/nf-syncmgr-isyncmgrcontrol-updatehandler) method is called.

#### Examples

The following example shows an implementation of this method that calls a private class function to retrieve the connected state.

```cpp
STDMETHODIMP CMyDeviceHandler::IsConnected()
{
    return (_IsConnected() ? S_OK : S_FALSE);
}

```