# ISyncMgrSyncCallback::ProposeItem

## Description

Proposes the addition of a new item to the set of items previously enumerated.

## Parameters

### `pNewItem` [in]

Type: **[ISyncMgrSyncItem](https://learn.microsoft.com/windows/desktop/api/syncmgr/nn-syncmgr-isyncmgrsyncitem)***

A pointer to an instance of [ISyncMgrSyncItem](https://learn.microsoft.com/windows/desktop/api/syncmgr/nn-syncmgr-isyncmgrsyncitem) representing the new item.

## Return value

Type: **HRESULT**

Returns S_OK if successful, or an error value otherwise. Returns E_INVALIDARG if *pszItemID* already exists.

## Remarks

**ISyncMgrSyncCallback::ProposeItem** is typically called when items are not considered part of the sync set unless they have been successfully synchronized. Sync Center does not display this item in the UI until the [ISyncMgrSyncCallback::CommitItem](https://learn.microsoft.com/windows/desktop/api/syncmgr/nf-syncmgr-isyncmgrsynccallback-commititem) method has been called.

#### Examples

The following example shows the usage of **ISyncMgrSyncCallback::ProposeItem** and [ISyncMgrSyncCallback::CommitItem](https://learn.microsoft.com/windows/desktop/api/syncmgr/nf-syncmgr-isyncmgrsynccallback-commititem) by the [Synchronize](https://learn.microsoft.com/windows/desktop/api/syncmgr/nf-syncmgr-isyncmgrhandler-synchronize) method.

```cpp
HRESULT CMyDeviceHandler::Synchronize(...)
{
    ...

    // Start synchronizing the handler.

    ...

    // Find items waiting to be created.
    for (...)
    {
        // Create the item.
        ISyncMgrSyncItem *pNewItem = NULL;
        LPWSTR szItemID[MAX_SYNCMGR_ID];

        hr = GetNextNewItem(&pNewItem, szItemID, ARRAYSIZE(szItemID));
        if (SUCCEEDED(hr))
        {
            // Propose this item to Sync Center.
            hr = pCallback->ProposeItem(pNewItem);
            if (SUCCEEDED(hr))
            {
                // Synchronize the item.
                // Synchronization was successful.  Commit the item.
                hr = pCallback->CommitItem(szItemID);
            }
            pNewItem->Release();
        }
    }
    ...
}

```