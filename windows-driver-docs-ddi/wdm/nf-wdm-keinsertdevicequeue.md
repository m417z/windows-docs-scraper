# KeInsertDeviceQueue function

## Description

The **KeInsertDeviceQueue** routine acquires the spin lock for the specified device queue object and, if the device queue is set to a busy state, queues the specified entry.

## Parameters

### `DeviceQueue` [in, out]

Pointer to a control object of type device queue for which the caller provides the storage.

### `DeviceQueueEntry` [in, out]

Pointer to the device queue entry that is to be inserted.

## Return value

If the device queue is empty, **FALSE** is returned and the *DeviceQueueEntry* is not inserted in the device queue.

## Remarks

If the device queue is set to a busy state, the specified *DeviceQueueEntry* is inserted at the tail of the device queue and the device queue spin lock is released.

If **KeInsertDeviceQueue** returns **FALSE**, the entry was not queued and the caller must begin processing the IRP. A call to **KeInsertDeviceQueue** or [KeInsertByKeyDeviceQueue](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keinsertbykeydevicequeue) when the queue is empty causes the device queue to change from a not-busy state to a busy state.

This routine is for code that queues an I/O request to a device driver.

## See also

[KeInitializeDeviceQueue](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keinitializedevicequeue)

[KeInsertByKeyDeviceQueue](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keinsertbykeydevicequeue)

[KeRemoveDeviceQueue](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keremovedevicequeue)

[KeRemoveEntryDeviceQueue](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keremoveentrydevicequeue)