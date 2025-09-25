# _BDCB_STATUS_UPDATE_CONTEXT structure

## Description

The BDCB_STATUS_UPDATE_CONTEXT structure describes a status update provided by Windows to a boot-start driver's [BOOT_DRIVER_CALLBACK_FUNCTION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-ioregisterbootdrivercallback) routine.

## Members

### `StatusType`

The type of the status update.

## Remarks

Boot-start drivers must not unregister their boot-start driver callbacks during a callback. Doing so may result in a bug check. To properly unregister a boot-driver callback, boot-start drivers must specify an [Unload](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-driver_unload) routine in their [driver object](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_driver_object) and call [IoUnRegisterBootDriverCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-iounregisterbootdrivercallback) from within the Unload dispatch routine.

## See also

[BDCB_STATUS_UPDATE_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ne-ntddk-_bdcb_status_update_type)

[BOOT_DRIVER_CALLBACK_FUNCTION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-ioregisterbootdrivercallback)

[IoUnRegisterBootDriverCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-iounregisterbootdrivercallback)