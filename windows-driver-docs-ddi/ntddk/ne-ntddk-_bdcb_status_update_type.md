# _BDCB_STATUS_UPDATE_TYPE enumeration

## Description

The BDCB_STATUS_UPDATE_TYPE enumeration lists the types of boot-driver callback status updates.

## Constants

### `BdCbStatusPrepareForDependencyLoad`

Windows will start loading driver dependencies next.

### `BdCbStatusPrepareForDriverLoad`

Windows has completed loading driver dependencies and will start loading boot-start drivers.

### `BdCbStatusPrepareForUnload`

Windows has completed the initialization of all boot-start drivers. After the completion of this callback, the Boot Driver Callback Facility will be torn down and no more callbacks will be received. During this callback, Early Launch AM drivers must clean up and prepare to be unloaded.

## See also

[BDCB_STATUS_UPDATE_CONTEXT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_bdcb_status_update_context)

[BOOT_DRIVER_CALLBACK_FUNCTION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-ioregisterbootdrivercallback)