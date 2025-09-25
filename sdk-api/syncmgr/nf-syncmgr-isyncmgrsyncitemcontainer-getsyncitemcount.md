# ISyncMgrSyncItemContainer::GetSyncItemCount

## Description

Gets a count of the sync items in the container.

## Parameters

### `pcItems` [out]

Type: **ULONG***

When this method returns, contains a pointer to the number of items in the container. This is the number of items enumerated by [IEnumSyncMgrSyncItems](https://learn.microsoft.com/windows/desktop/api/syncmgr/nn-syncmgr-ienumsyncmgrsyncitems).

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.