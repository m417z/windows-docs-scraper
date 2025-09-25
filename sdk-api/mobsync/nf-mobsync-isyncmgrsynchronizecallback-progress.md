# ISyncMgrSynchronizeCallback::Progress

## Description

Called by a registered application to update the progress information and determine whether an operation should continue.

## Parameters

### `ItemID` [in]

Type: **REFGUID**

A reference to the item identifier for an item that is being updated.

### `pSyncProgressItem` [in]

Type: **const [SYNCMGRPROGRESSITEM](https://learn.microsoft.com/windows/desktop/api/mobsync/ns-mobsync-syncmgrprogressitem)***

A pointer to a [SYNCMGRPROGRESSITEM](https://learn.microsoft.com/windows/desktop/api/mobsync/ns-mobsync-syncmgrprogressitem) structure that contains the updated progress information.

## Return value

Type: **HRESULT**

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Continues the synchronization. |
| **S_SYNCMGR_CANCELITEM** | Cancels the synchronization on a specified item, as soon as possible. |
| **S_SYNCMGR_CANCELALL** | Cancels the synchronization on all items that are associated with this application, as soon as possible. |

## Remarks

Registered applications should call this method to provide normal feedback even when the [SYNCMGRFLAG_MAYBOTHERUSER](https://learn.microsoft.com/windows/desktop/api/mobsync/ne-mobsync-syncmgrflag) flag is set.

## See also

[ISyncMgrSynchronizeCallback](https://learn.microsoft.com/windows/desktop/api/mobsync/nn-mobsync-isyncmgrsynchronizecallback)

[SYNCMGRFLAG](https://learn.microsoft.com/windows/desktop/api/mobsync/ne-mobsync-syncmgrflag)

[SYNCMGRPROGRESSITEM](https://learn.microsoft.com/windows/desktop/api/mobsync/ns-mobsync-syncmgrprogressitem)