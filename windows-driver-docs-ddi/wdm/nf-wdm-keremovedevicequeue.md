# KeRemoveDeviceQueue function

## Description

The **KeRemoveDeviceQueue** routine removes an entry from the head of a specified device queue.

## Parameters

### `DeviceQueue` [in, out]

Pointer to an initialized device queue object for which the caller provides the storage.

## Return value

If the device queue is empty but is set to a busy state, **KeRemoveDeviceQueue** returns **NULL**.

## Remarks

The specified device queue spin lock is acquired and the state of the device queue is checked. If the device queue is set to a busy state and an IRP is queued, this routine dequeues the entry and returns a pointer to the IRP. A call to **KeRemoveDeviceQueue** when the device queue object is set to a busy state but no IRPs are queued causes a state change to not-busy. The specified device queue's spin lock is released.

It is an error to call **KeRemoveDeviceQueue** when the device queue object is set to a not-busy state.

## See also

[KeInitializeDeviceQueue](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keinitializedevicequeue)

[KeInsertByKeyDeviceQueue](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keinsertbykeydevicequeue)

[KeInsertDeviceQueue](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keinsertdevicequeue)

[KeRemoveByKeyDeviceQueue](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keremovebykeydevicequeue)

[KeRemoveEntryDeviceQueue](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keremoveentrydevicequeue)