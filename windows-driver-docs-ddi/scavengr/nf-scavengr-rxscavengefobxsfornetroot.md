# RxScavengeFobxsForNetRoot function

## Description

**RxScavengeFobxsForNetRoot** scavenges all of the FOBX structures associated with a given NET_ROOT structure.

## Parameters

### `NetRoot`

A pointer to the NET_ROOT structure for which the FOBX structures need to be scavenged.

### `PurgingFcb`

A pointer to the FCB for which the scavenging should occur.

### `SynchronizeWithScavenger`

A Boolean value that specifies if this routine should synchronize with the scavenger.

## Remarks

At cleanup, there are no more user handles associated with the file object. In such cases, the time window between close and cleanup is dictated by the additional references maintained by the memory manager and cache manager. On cleanup, the FOBX is put on a close pending list and removed from the corresponding list when a close operation is received. In the interim, if an open operation is failing with ACCESS_DENIED status, then RDBSS can force a purge and scavenge of the FOBX structure. This is a synchronous operation.

For directory renames, all files under the directory need to be closed. So, a network mini-redirector might call **RxPurgeRelatedFobxs** and **RxScavengeFobxsForNetRoot** in response to a IRP_MJ_SET_INFORMATION request to rename a directory. By passing in the NET_ROOT structure for the directory and a **NULL** FCB, all of the FOBX structures associated with the directory would be purged and scavenged.

The **RxScavengeFobxsForNetRoot** routine acquires the scavenger mutex, traverses the **FobxsToBeFinalized** list member of the scavenger object and adds any entries found to tail of the **ScavengerFinalizationList** member of the scavenger object, and then releases the mutex.

If *PurgingFcb* is not **NULL**, and this purging FCB structure is not the same as the FCB associated with the FOBX structure on the **FobxsToBeFinalized** list member of the scavenger object, **RxScavengeFobxsForNetRoot** will call the [MRxAreFilesAliased](https://learn.microsoft.com/windows-hardware/drivers/ddi/mrx/nc-mrx-pmrx_chkfcb_calldown) callback routine provided by the network mini-redirector if it is supported. The call to **MRxAreFilesAliased** is to determine if the PFCB is an alias for the FCB associated with the FOBX structure.

On checked builds, **RxScavengeAllFobxs** causes the system to ASSERT for the following condition:

* The **NodeTypeCode** member of an FOBX structure is not RDBSS_NTC_FOBX.

## See also

[MRxAreFilesAliased](https://learn.microsoft.com/windows-hardware/drivers/ddi/mrx/nc-mrx-pmrx_chkfcb_calldown)

[RxPurgeAllFobxs](https://learn.microsoft.com/windows-hardware/drivers/ddi/rxprocs/nf-rxprocs-rxpurgeallfobxs)

[RxPurgeRelatedFobxs](https://learn.microsoft.com/windows-hardware/drivers/ddi/scavengr/nf-scavengr-rxpurgerelatedfobxs)

[RxScavengeAllFobxs](https://learn.microsoft.com/windows-hardware/drivers/ddi/rxprocs/nf-rxprocs-rxscavengeallfobxs)