# _WDF_REMOVE_LOCK_OPTIONS_FLAGS enumeration

## Description

[Applies to KMDF only]

The **WDF_REMOVE_LOCK_OPTIONS_FLAGS** enumeration type defines flags that are used in a driver's [WDF_REMOVE_LOCK_OPTIONS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/ns-wdfdevice-_wdf_remove_lock_options) structure.

## Constants

### `WDF_REMOVE_LOCK_OPTION_ACQUIRE_FOR_IO:0x00000001`

Specifies that the framework should acquire a remove lock before delivering an IRP of any type to the driver.

## Remarks

For more information about using remove locks in a framework-based driver, see [WdfDeviceInitSetRemoveLockOptions](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdeviceinitsetremovelockoptions).

## See also

[WDF_REMOVE_LOCK_OPTIONS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/ns-wdfdevice-_wdf_remove_lock_options)

[WDF_REMOVE_LOCK_OPTIONS_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdf_remove_lock_options_init)

[WdfDeviceInitSetRemoveLockOptions](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdeviceinitsetremovelockoptions)