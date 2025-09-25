# KeFlushQueuedDpcs function

## Description

The **KeFlushQueuedDpcs** routine returns after all currently queued DPCs on all processors have executed their DPC routines to completion.

## Remarks

Drivers can use this routine to wait until all currently-queued DPCs are run. Note that **KeFlushQueuedDpcs** can take a long time to return, so drivers should not use it along any critical code paths.

Only DPCs queued prior to the call to **KeFlushQueuedDpcs** are guaranteed to have been executed to completion upon return. No guarantee is made for DPCs that are queued during the call to **KeFlushQueuedDpcs**.

## See also

[IoInitializeDpcRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioinitializedpcrequest)

[IoRequestDpc](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iorequestdpc)

[KeInitializeDpc](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keinitializedpc)

[KeInsertQueueDpc](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keinsertqueuedpc)