# RxScavengeAllFobxs function

## Description

**RxScavengeAllFobxs** scavenges all of the FOBX structures associated with a network mini-redirector device object.

## Parameters

### `RxDeviceObject`

A pointer to the mini-redirector device object for which the scavenge should be done.

## Remarks

At cleanup, there are no more user handles associated with the file object. In such cases, the time window between close and cleanup is dictated by the additional references maintained by the memory manager and cache manager. RDBSS uses a scavenger process running on a separate thread to scavenge and purge unneeded FOBX and other structures.

A network mini-redirectors might call **RxPurgeAllFobxs** and **RxScavengeAllFobsx** in response to a PnP power change event.

The **RxScavengeAllFobxs** routine acquires the scavenger mutex, traverses the **FobxFinalizationList** member on the scavenger object, and inserts any entries found at the tail of the **ScavengerFinalizationList** member, and then releases the scavenger mutex.

On checked builds, **RxScavengeAllFobxs** causes the system to ASSERT for the following condition:

* The **NodeTypeCode** member of an FOBX structure is not RDBSS_NTC_FOBX.

## See also

[RxPurgeAllFobxs](https://learn.microsoft.com/windows-hardware/drivers/ddi/rxprocs/nf-rxprocs-rxpurgeallfobxs)

[RxPurgeRelatedFobxs](https://learn.microsoft.com/windows-hardware/drivers/ddi/scavengr/nf-scavengr-rxpurgerelatedfobxs)

[RxScavengeFobxsForNetRoot](https://learn.microsoft.com/windows-hardware/drivers/ddi/scavengr/nf-scavengr-rxscavengefobxsfornetroot)