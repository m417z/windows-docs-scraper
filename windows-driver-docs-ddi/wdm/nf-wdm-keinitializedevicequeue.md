# KeInitializeDeviceQueue function

## Description

The **KeInitializeDeviceQueue** routine initializes a device queue object to a not-busy state.

## Parameters

### `DeviceQueue` [out]

Pointer to a device queue object for which the caller provides the storage.

## Remarks

**KeInitializeDeviceQueue** initializes the specified device queue and sets its state to not-busy.

A driver should call **KeInitializeDeviceQueue** from its *AddDevice* routine after creating the device object for the associated device. Storage for the device queue object must be resident: in the device extension of a driver-created device object, in the controller extension of a driver-created controller object, or in nonpaged pool allocated by the caller.

## See also

[KeInsertByKeyDeviceQueue](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keinsertbykeydevicequeue)

[KeInsertDeviceQueue](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keinsertdevicequeue)

[KeRemoveDeviceQueue](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keremovedevicequeue)

[KeRemoveEntryDeviceQueue](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keremoveentrydevicequeue)