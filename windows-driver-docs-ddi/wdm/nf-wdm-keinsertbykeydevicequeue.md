# KeInsertByKeyDeviceQueue function

## Description

The **KeInsertByKeyDeviceQueue** routine acquires the spin lock for the specified *DeviceQueue* and queues an entry according to the specified sort-key value if the device queue is set to a busy state.

## Parameters

### `DeviceQueue` [in, out]

Pointer to a control object of the device queue type for which the caller provides the storage.

### `DeviceQueueEntry` [in, out]

Pointer to the device queue entry to be inserted into the device queue according to the specific key value.

### `SortKey` [in]

Specifies the sort-key value that determines the position in the device queue in which to insert the entry.

## Return value

If the device queue is empty, **FALSE** is returned, meaning the *DeviceQueueEntry* is not inserted in the device queue.

## Remarks

The specified device queue spin lock is acquired and the state of the device queue is checked. If the device queue is set to a busy state, the IRP specified by the *DeviceQueueEntry* is inserted into the device queue according to its sort key value and the device queue spin lock is released.

The new entry is positioned in the device queue after any entries in the queue with sort key values less than or equal to its sort key value and preceding any entries with sort key values that are greater.

If **KeInsertByKeyDeviceQueue** returns **FALSE**, the caller must begin processing the IRP. A call to [KeInsertDeviceQueue](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keinsertdevicequeue) or **KeInsertByKeyDeviceQueue** when the queue is empty causes the device queue to transition from a not-busy state to a busy state.

This routine is for code that queues an I/O request to a device driver.

## See also

[KeInitializeDeviceQueue](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keinitializedevicequeue)

[KeInsertDeviceQueue](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keinsertdevicequeue)

[KeRemoveDeviceQueue](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keremovedevicequeue)

[KeRemoveEntryDeviceQueue](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keremoveentrydevicequeue)