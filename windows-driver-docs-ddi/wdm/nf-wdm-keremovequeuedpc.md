# KeRemoveQueueDpc function

## Description

The **KeRemoveQueueDpc** routine removes the specified DPC object from the system DPC queue.

## Parameters

### `Dpc` [in, out]

A pointer to an initialized DPC object that was queued by a previous call to the [KeInsertQueueDpc](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keinsertqueuedpc) routine.

## Return value

**KeRemoveQueueDpc** returns **TRUE** if the DPC object is in the DPC queue. If the specified DPC object is not currently in the DPC queue, no operation is performed and **FALSE** is returned.

## Remarks

If the specified DPC object is currently queued, it is removed from the queue, canceling a call to the associated DPC routine.

Starting with Windows Vista with Service Pack 1 (SP1) and Windows Server 2008, a return value of **TRUE** always means that **KeRemoveQueueDpc** successfully removed the DPC object from the DPC queue before the DPC routine started to run. In earlier versions of Windows, the DPC routine might occasionally run even if **KeRemoveQueueDpc** returns **TRUE**. In these earlier versions of Windows, drivers that cannot tolerate ambiguity in the **TRUE** return value should treat return values of **TRUE** and **FALSE** identically.

## See also

[KeInitializeDpc](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keinitializedpc)

[KeInsertQueueDpc](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keinsertqueuedpc)