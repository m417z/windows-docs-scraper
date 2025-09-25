# _WDF_DRIVER_INIT_FLAGS enumeration

## Description

[Applies to KMDF and UMDF]

The WDF_DRIVER_INIT_FLAGS enumeration specifies driver initialization flags.

## Constants

### `WdfDriverInitNonPnpDriver:0x00000001`

The driver does not support Plug and Play (PnP). If this value is set, the driver must not supply an [EvtDriverDeviceAdd](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdriver/nc-wdfdriver-evt_wdf_driver_device_add) callback function. For more information about non-PnP drivers, see [Using Kernel-Mode Driver Framework with Non-PnP Drivers](https://learn.microsoft.com/windows-hardware/drivers/wdf/using-kernel-mode-driver-framework-with-non-pnp-drivers).

### `WdfDriverInitNoDispatchOverride:0x00000002`

The driver is a miniport driver and, therefore, the framework must not provide dispatch routines for the driver. In other words, the framework must not intercept I/O request packets (IRPs) that the I/O manager has directed to the driver. In addition, the driver must call [WdfDriverMiniportUnload](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfminiport/nf-wdfminiport-wdfdriverminiportunload) when the port driver informs the miniport driver that it is about to be unloaded. For more information about this flag and how to write framework-based miniport drivers, see [Using Kernel-Mode Driver Framework with Miniport Drivers](https://learn.microsoft.com/windows-hardware/drivers/wdf/creating-kmdf-miniport-drivers).

### `WdfVerifyOn:0x00000004`

Reserved for system use. Drivers must not use this flag.

### `WdfVerifierOn:0x00000008`

Reserved for system use. Drivers must not use this flag.

### `WdfDriverInitCompanion:0x00000010`

## Remarks

The WDF_DRIVER_INIT_FLAGS enumeration is used to specify the value for the **DriverInitFlags** member of the [WDF_DRIVER_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdriver/ns-wdfdriver-_wdf_driver_config) structure.

## See also

[EvtDriverDeviceAdd](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdriver/nc-wdfdriver-evt_wdf_driver_device_add)

[WDF_DRIVER_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdriver/ns-wdfdriver-_wdf_driver_config)

[WdfDriverMiniportUnload](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfminiport/nf-wdfminiport-wdfdriverminiportunload)