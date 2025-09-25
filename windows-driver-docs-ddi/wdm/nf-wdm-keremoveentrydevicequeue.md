# KeRemoveEntryDeviceQueue function

## Description

The **KeRemoveEntryDeviceQueue** routine returns whether the specified entry is in the device queue and removes it, if it was queued, from the device queue.

## Parameters

### `DeviceQueue` [in, out]

Pointer to an initialized device queue object for which the caller provides the storage.

### `DeviceQueueEntry` [in, out]

Pointer to the entry to be removed from the specified *DeviceQueue*.

## Return value

If the *DeviceQueueEntry* is queued, it is removed and **KeRemoveEntryDeviceQueue** returns **TRUE**.

## Remarks

The IRQL is set to DISPATCH_LEVEL and the *DeviceQueue* spin lock is acquired.

If the specified *DeviceQueueEntry* is not in the queue, the IRP either is already being processed, or the IRP has been canceled. In this case, **KeRemoveEntryDeviceQueue** simply returns **FALSE**.

The specified *DeviceQueue* spin lock is released and IRQL is restored to its previous value.

## See also

[KeInitializeDeviceQueue](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keinitializedevicequeue)

[KeInsertByKeyDeviceQueue](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keinsertbykeydevicequeue)

[KeInsertDeviceQueue](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keinsertdevicequeue)

[KeRemoveByKeyDeviceQueue](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keremovebykeydevicequeue)

[KeRemoveDeviceQueue](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keremovedevicequeue)