# ISyncMgrSyncItem::GetItemInfo

## Description

Gets the properties of a sync item.

## Parameters

### `ppItemInfo` [out]

Type: **[ISyncMgrSyncItemInfo](https://learn.microsoft.com/windows/desktop/api/syncmgr/nn-syncmgr-isyncmgrsynciteminfo)***

When this method returns, contains the address of a pointer to an instance of the [ISyncMgrSyncItemInfo](https://learn.microsoft.com/windows/desktop/api/syncmgr/nn-syncmgr-isyncmgrsynciteminfo) interface, representing the item.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

If **GetItemInfo** fails, the sync item is still shown in the handler's folder and Sync Center continues to synchronize it, but default values are used for all properties.

#### Examples

The following example shows an implementation of this method.

```cpp
STDMETHODIMP CMyDeviceSyncItem::GetItemInfo(
                              __out ISyncMgrSyncItemInfo **ppItemInfo)
{
    *ppItemInfo = NULL;

    HRESULT hr = QueryInterface(IID_ISyncMgrSyncItemInfo, (void**)ppItemInfo);
    return hr;
}

```