# KeRemoveByKeyDeviceQueue function

## Description

The **KeRemoveByKeyDeviceQueue** routine removes an entry, selected according to a sort key value, from the specified device queue.

## Parameters

### `DeviceQueue` [in, out]

Pointer to an initialized device queue object for which the caller provides the storage.

### `SortKey` [in]

Specifies the key to be used when searching the *DeviceQueue*.

## Return value

**KeRemoveByKeyDeviceQueue** returns the device queue entry that was removed; returns **NULL** if the queue was empty.

## Remarks

This routine searches for the first entry in the device queue that has a value greater than or equal to the *SortKey*. After this entry is found, this routine removes the entry from the device queue and returns it. If no such entry is found, then the first entry in the queue is returned. If the device queue is empty, then the device is set to a not-busy state and a **NULL** pointer is returned.

It is an error to call **KeRemoveByKeyDeviceQueue** when the device queue object is set to a not-busy state.

## See also

[KeInitializeDeviceQueue](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keinitializedevicequeue)

[KeInsertByKeyDeviceQueue](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keinsertbykeydevicequeue)

[KeInsertDeviceQueue](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keinsertdevicequeue)

[KeRemoveDeviceQueue](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keremovedevicequeue)

[KeRemoveEntryDeviceQueue](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keremoveentrydevicequeue)