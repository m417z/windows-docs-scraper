# WdfDeviceInitSetRemoveLockOptions function

## Description

[Applies to KMDF only]

 The **WdfDeviceInitSetRemoveLockOptions** method causes the framework to acquire a remove lock before delivering an IRP of any type to the driver.

## Parameters

### `DeviceInit` [in]

A caller-supplied pointer to a [WDFDEVICE_INIT](https://learn.microsoft.com/windows-hardware/drivers/wdf/wdfdevice_init) structure.

### `Options` [in]

A pointer to a [WDF_REMOVE_LOCK_OPTIONS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/ns-wdfdevice-_wdf_remove_lock_options) structure.

## Remarks

By default, the framework acquires a remove lock before it delivers IRPs of the following major types to the driver:

IRP_MJ_PNP

IRP_MJ_POWER

IRP_MJ_SYSTEM_CONTROL

When the IRP completes, the framework releases the remove lock.

Starting in KMDF 1.11, the driver can optionally call **WdfDeviceInitSetRemoveLockOptions** to cause the framework to acquire a remove lock before delivering all IRP types, not just those listed above.

If your driver has kernel-mode clients that send I/O unsynchronized with the PnP state of your device, you may experience crashes due to I/O IRPs arriving after the framework device object has been removed. In this case, you can call **WdfDeviceInitSetRemoveLockOptions**. Then, when a client sends an I/O request to your device:

* If the device has not yet been removed, the remove lock is acquired successfully and the request is delivered. If removal happens later, the framework calls [**IoReleaseRemoveLockAndWait**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioreleaseremovelockandwait) which blocks until all successful lock acquisitions are released (I/O requests are completed).
* If the device has already processed IRP_MN_REMOVE_DEVICE, but there is an outstanding reference to a WDM device object preventing the device from being released, the remove lock is not acquired and the framework completes the request immediately.

**Note** **WdfDeviceInitSetRemoveLockOptions** is not supported on control objects.

Typically, a driver calls **WdfDeviceInitSetRemoveLockOptions** from within its [EvtDriverDeviceAdd](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdriver/nc-wdfdriver-evt_wdf_driver_device_add) callback function, just before calling [WdfDeviceCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicecreate).

After a driver calls **WdfDeviceInitSetRemoveLockOptions**, the setting remains in effect for the lifetime of the framework device object.

For more information about remove locks, see [Using Remove Locks](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-remove-locks).

#### Examples

This code example initializes a [WDF_REMOVE_LOCK_OPTIONS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/ns-wdfdevice-_wdf_remove_lock_options) structure and calls **WdfDeviceInitSetRemoveLockOptions**.

```cpp

WDF_REMOVE_LOCK_OPTIONS RemoveLockOptions;

WDF_REMOVE_LOCK_OPTIONS_INIT(
                             &RemoveLockOptions,
                             WDF_REMOVE_LOCK_OPTION_ACQUIRE_FOR_IO
                             );
WdfDeviceInitSetRemoveLockOptions(
                                  DeviceInit,
                                  &RemoveLockOptions
                                  );
```

## See also

[WDF_REMOVE_LOCK_OPTIONS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/ns-wdfdevice-_wdf_remove_lock_options)

[WDF_REMOVE_LOCK_OPTIONS_FLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/ne-wdfdevice-_wdf_remove_lock_options_flags)

[WDF_REMOVE_LOCK_OPTIONS_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdf_remove_lock_options_init)