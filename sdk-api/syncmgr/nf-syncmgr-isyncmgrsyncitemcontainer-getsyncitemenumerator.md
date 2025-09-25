# ISyncMgrSyncItemContainer::GetSyncItemEnumerator

## Description

Gets an interface that enumerates the handler's sync items.

## Parameters

### `ppenum` [out]

Type: **[IEnumSyncMgrSyncItems](https://learn.microsoft.com/windows/desktop/api/syncmgr/nn-syncmgr-ienumsyncmgrsyncitems)****

When this method returns, contains the address of a pointer to an [IEnumSyncMgrSyncItems](https://learn.microsoft.com/windows/desktop/api/syncmgr/nn-syncmgr-ienumsyncmgrsyncitems) instance. **IEnumSyncMgrSyncItems** can be used to retrieve an interface for each sync item in the set.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This method replaces the older [EnumSyncMgrItems](https://learn.microsoft.com/windows/desktop/api/mobsync/nf-mobsync-isyncmgrsynchronize-enumsyncmgritems) method. The older method returned an enumerator interface which returned a [SYNCMGRITEM](https://learn.microsoft.com/windows/desktop/api/mobsync/ns-mobsync-syncmgritem) structure for each sync item. To get the data previously provided by that structure, Sync Center calls [QueryInterface](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-queryinterface(q)) on each item's [ISyncMgrSyncItem](https://learn.microsoft.com/windows/desktop/api/syncmgr/nn-syncmgr-isyncmgrsyncitem) interface to request a corresponding [ISyncMgrSyncItemInfo](https://learn.microsoft.com/windows/desktop/api/syncmgr/nn-syncmgr-isyncmgrsynciteminfo) interface.

The number of enumerated items can be obtained through the [ISyncMgrSyncItemContainer::GetSyncItemCount](https://learn.microsoft.com/windows/desktop/api/syncmgr/nf-syncmgr-isyncmgrsyncitemcontainer-getsyncitemcount) method.

#### Examples

The following example shows an implementation of this method.

```cpp
STDMETHODIMP CMyDeviceHandler::GetSyncItemEnumerator(
    __out IEnumSyncMgrSyncItems **ppenum)
{
    *ppenum = NULL;

    // Load the items using a private class method.
    HRESULT hr = _LoadItems();

    if (SUCCEEDED(hr))
    {
        hr = CEnumSyncMgrSyncItems_CreateInstance(this,
                                                  IID_PPV_ARGS(ppenum));
    }

    return hr;
}

```