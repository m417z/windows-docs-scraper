# _WDF_REMOVE_LOCK_OPTIONS structure

## Description

[Applies to KMDF only]

 The **WDF_REMOVE_LOCK_OPTIONS** structure specifies options for acquiring a remove lock before delivering an IRP to the driver.

## Members

### `Size`

The size of the structure, in bytes.

### `Flags`

The bitwise **OR** of values from the [WDF_REMOVE_LOCK_OPTIONS_FLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/ne-wdfdevice-_wdf_remove_lock_options_flags) enumeration.

## See also

[WDF_REMOVE_LOCK_OPTIONS_FLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/ne-wdfdevice-_wdf_remove_lock_options_flags)

[WDF_REMOVE_LOCK_OPTIONS_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdf_remove_lock_options_init)

[WdfDeviceInitSetRemoveLockOptions](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdeviceinitsetremovelockoptions)