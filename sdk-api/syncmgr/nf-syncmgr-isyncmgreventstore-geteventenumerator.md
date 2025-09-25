# ISyncMgrEventStore::GetEventEnumerator

## Description

Gets an enumerator for a handler's events.

## Parameters

### `ppenum` [out]

Type: **[IEnumSyncMgrEvents](https://learn.microsoft.com/windows/desktop/api/syncmgr/nn-syncmgr-ienumsyncmgrevents)****

When this method returns, contains the address of a pointer to an [IEnumSyncMgrEvents](https://learn.microsoft.com/windows/desktop/api/syncmgr/nn-syncmgr-ienumsyncmgrevents) instance that can be used to access the handler's events.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This method is called by Sync Center when the user navigates to the Sync Results folder or clicks the **Errors** link for a handler.

#### Examples

The following example shows an implementation of **ISyncMgrEventStore::GetEventEnumerator**.

```cpp
STDMETHODIMP CMyDeviceEventStore::GetEventEnumerator(
                                __out IEnumSyncMgrEvents **ppenum)
{
    HRESULT hr = CEnumMyDeviceSyncMgrEvents_Create(ppenum);
    return hr;
}

```