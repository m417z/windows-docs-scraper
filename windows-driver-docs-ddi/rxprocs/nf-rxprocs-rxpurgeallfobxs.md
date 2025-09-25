# RxPurgeAllFobxs function

## Description

**RxPurgeAllFobxs** purges all of the FOBX structures associated with a network mini-redirector.

## Parameters

### `RxDeviceObject`

A pointer to the mini-redirector device object for which the purge should be done.

## Remarks

At cleanup, there are no more user handles associated with the file object. In such cases, the time window between close and cleanup is dictated by the additional references maintained by memory manager and cache manager. RDBSS uses a scavenger process running on a separate thread to scavenge and purge unneeded FOBX and other structures.

A network mini-redirector might call **RxPurgeAllFobxs** and **RxScavengeAllFobsx** in response to a PnP power change event.

The **RxPurgeAllFobxs** routine acquires the scavenger mutex, traverses the **ClosePendingFobxsList** member on the scavenger object removing list entries, and then releases the mutex. If the FOBX structure is not **NULL**, **RxPurgeAllFobxs** will purge the FOBX structure and try to acquire an exclusive lock on the associated FCB structure. If successful, **RxPurgeAllFobxs** will then try to dereference the NET_FOBX structure and dereference, finalize, and release the FCB structure.

On checked builds, **RxPurgeAllFobxs** causes the system to ASSERT for a number of conditions including the following:

* The **Flink** member of *RxScavenger->ClosePendingFobxsList* structure on the **RxDeviceObject** is **NULL**.
* *Fobx->NodeTypeCode* is not RDBSS_NTC_FOBX.
* The **Flink** and **Blink** members for a list entry are **NULL**.

## See also

[RxPurgeRelatedFobxs](https://learn.microsoft.com/windows-hardware/drivers/ddi/scavengr/nf-scavengr-rxpurgerelatedfobxs)

[RxScavengeAllFobxs](https://learn.microsoft.com/windows-hardware/drivers/ddi/rxprocs/nf-rxprocs-rxscavengeallfobxs)

[RxScavengeFobxsForNetRoot](https://learn.microsoft.com/windows-hardware/drivers/ddi/scavengr/nf-scavengr-rxscavengefobxsfornetroot)