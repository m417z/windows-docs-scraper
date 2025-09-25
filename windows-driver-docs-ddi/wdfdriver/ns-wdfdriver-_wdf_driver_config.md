# _WDF_DRIVER_CONFIG structure

## Description

[Applies to KMDF and UMDF]

The WDF_DRIVER_CONFIG structure is an input parameter to [WdfDriverCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdriver/nf-wdfdriver-wdfdrivercreate).

## Members

### `Size`

The size, in bytes, of this structure.

### `EvtDriverDeviceAdd`

A pointer to a driver's [EvtDriverDeviceAdd](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdriver/nc-wdfdriver-evt_wdf_driver_device_add) callback function.

### `EvtDriverUnload`

A pointer to a driver's [EvtDriverUnload](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdriver/nc-wdfdriver-evt_wdf_driver_unload) callback function.

### `DriverInitFlags`

A bitwise OR of one or more [WDF_DRIVER_INIT_FLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdriver/ne-wdfdriver-_wdf_driver_init_flags)-typed values that identify driver initialization flags.

### `DriverPoolTag`

(KMDF versions 1.5 and later.) A driver-defined pool tag that the framework will assign to all of the driver's pool allocations. Debuggers display this tag. For more information about specifying a pool tag, see the following Remarks section.

## Remarks

Your driver can optionally specify a pool tag that the framework will assign to all of the driver's pool allocations. Drivers typically specify a character string of up to four characters, delimited by single quotation marks, in reverse order (for example, 'dcba'). The ASCII value of each character in the tag must be between 0 and 127.

If **DriverPoolTag** is zero, the framework creates a default pool tag by using the first four characters of your driver's kernel-mode service name. If the service name begins with "WDF" (the name is not case sensitive and does not include the quotation marks), the next four characters are used. If fewer than four characters are available, "FxDr" is used.

To initialize a WDF_DRIVER_CONFIG structure, drivers must call [WDF_DRIVER_CONFIG_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdriver/nf-wdfdriver-wdf_driver_config_init).

## See also

[EvtDriverDeviceAdd](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdriver/nc-wdfdriver-evt_wdf_driver_device_add)

[EvtDriverUnload](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdriver/nc-wdfdriver-evt_wdf_driver_unload)

[WDF_DRIVER_CONFIG_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdriver/nf-wdfdriver-wdf_driver_config_init)

[WDF_DRIVER_INIT_FLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdriver/ne-wdfdriver-_wdf_driver_init_flags)

[WdfDriverCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdriver/nf-wdfdriver-wdfdrivercreate)