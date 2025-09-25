# ISyncMgrHandlerInfo::GetLastSyncTime

## Description

Gets the date and time when the handler was last synchronized.

## Parameters

### `pftLastSync` [out]

Type: **FILETIME***

When this method returns, contains a pointer to a [FILETIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-filetime) structure containing the date and time information.

## Return value

Type: **HRESULT**

Returns S_OK if successful, or an error value otherwise. If the method fails, *pftLastSync* points to the value from the previous synchronization.

## Remarks

This value is not displayed in the folder UI by default, but is available as the System.Sync.DateSynchronized (PKEY_Sync_DateSynchronized) property.

Sync Center calls this method whenever the [UpdateHandler](https://learn.microsoft.com/windows/desktop/api/syncmgr/nf-syncmgr-isyncmgrcontrol-updatehandler) method is called.

#### Examples

The following example shows an implementation of this method that calls a private class function to retrieve the time and date.

```cpp
STDMETHODIMP CMyDeviceHandler::GetLastSyncTime(__out FILETIME *pftLastSync)
{
    *pftLastSync = _ftLastSync;
    return S_OK;
}

```