# RxPurgeRelatedFobxs function

## Description

**RxPurgeRelatedFobxs** purges all of the FOBX structures associated with a NET_ROOT structure.

## Parameters

### `NetRoot`

A pointer to the NET_ROOT structure for which the FOBX structures need to be purged.

### `RxContext`

A pointer to the RX_CONTEXT structure.

### `AttemptFinalization`

A Boolean value that indicates whether an attempt to finalize and release the associated FCB structure should occur.

### `PurgingFcb`

A pointer to the FCB structure for which purging should occur.

## Return value

**RxPurgeRelatedFobxs** returns STATUS_SUCCESS on success or one of the following error values on failure:

| Return code | Description |
| --- | --- |
| **STATUS_UNSUCCESSFUL** | No related FOBX structures could be purged. |

## Remarks

At cleanup there are no more user handles associated with the file object. In such cases, the time window between close and cleanup is dictated by the additional references maintained by the memory manager and cache manager. On cleanup, the FOBX is put on a close pending list and removed from the corresponding list when a close operation is received. In the interim, if an open operation is failing with ACCESS_DENIED status, then RDBSS can force a purge of the FOBX structure. This is a synchronous operation.

For directory renames, all files under the directory need to be closed. A network mini-redirector might call **RxPurgeRelatedFobxs** and **RxScavengeFobxsForNetRoot** in response to an IRP_MJ_SET_INFORMATION request to rename a directory. By passing in the NET_ROOT structure for the directory and a **NULL** FCB, all of the FOBX structures associated with the directory would be purged and scavenged.

The **RxPurgeRelatedFobxs** routine attempts to purge all of the FOBX structures that had a close operation pending before the purge request was received. The **RxPurgeRelatedFobxs** routine acquires the scavenger mutex, traverses the **ClosePendingFobxsList** member on the scavenger object removing list entries, and then releases the mutex.

If *AttemptFinalize* is set to **TRUE**, then **RxPurgeRelatedFobxs** will try to finalize and release the associated FCB.

If *PFCB* is not **NULL**, and this purging FCB structure is not the same as the FCB structure associated with the FOBX on the **ClosePendingFobxsList** member, then **RxPurgeRelatedFobxs** will call the [MRxAreFilesAliased](https://learn.microsoft.com/windows-hardware/drivers/ddi/mrx/nc-mrx-pmrx_chkfcb_calldown) callback routine provided by the network mini-redirector if this routine is supported. The call to **MRxAreFilesAliased** is to determine if the PFCB is an alias for the FCB associated with the FOBX structure.

## See also

[MRxAreFilesAliased](https://learn.microsoft.com/windows-hardware/drivers/ddi/mrx/nc-mrx-pmrx_chkfcb_calldown)

[RxPurgeAllFobxs](https://learn.microsoft.com/windows-hardware/drivers/ddi/rxprocs/nf-rxprocs-rxpurgeallfobxs)

[RxScavengeAllFobxs](https://learn.microsoft.com/windows-hardware/drivers/ddi/rxprocs/nf-rxprocs-rxscavengeallfobxs)

[RxScavengeFobxsForNetRoot](https://learn.microsoft.com/windows-hardware/drivers/ddi/scavengr/nf-scavengr-rxscavengefobxsfornetroot)