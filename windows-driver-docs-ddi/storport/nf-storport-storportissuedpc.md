# StorPortIssueDpc function

## Description

The **StorPortIssueDpc** routine issues a deferred procedure call (DPC).

## Parameters

### `DeviceExtension` [in]

Pointer to the per-adapter device extension.

### `Dpc` [in]

Pointer to a buffer containing an initialized DPC object of type [STOR_DPC](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ns-storport-_stor_dpc) returned by the [StorPortInitializeDpc](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportinitializedpc) routine.

### `SystemArgument1` [in]

Pointer to caller-supplied information that will be passed to the deferred routine.

### `SystemArgument2` [in]

Pointer to caller-supplied information that will be passed to the deferred routine.

## Return value

The **StorPortIssueDpc** routine returns **TRUE** if the DPC was successfully inserted into the DPC queue, and **FALSE** otherwise.

## Remarks

The **StorPortIssueDpc** routine calls the [KeInsertQueueDpc](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keinsertqueuedpc) kernel routine to queue the DPC. The **KeInsertQueueDpc** kernel routine does not allow a DPC to be queued multiple times. Thus, if the DPC object specified by the *Dpc* parameter is already in the DPC queue, **KeInsertQueueDpc** ignores the queue request. This ensures that a deferred routine initialized with [StorPortInitializeDpc](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportinitializedpc) is always synchronized with itself. In other words, the caller does not need to sequentialize calls to the **StorPortIssueDpc** routine to ensure that multiple instances the routine do not run simultaneously.

If a miniport driver has multiple work-items that must be performed by the same DPC, the miniport driver must ensure that each work item completes before issuing the DPC for the next work item.

## See also

[KeInsertQueueDpc](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keinsertqueuedpc)

[STOR_DPC](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ns-storport-_stor_dpc)

[StorPortInitializeDpc](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportinitializedpc)