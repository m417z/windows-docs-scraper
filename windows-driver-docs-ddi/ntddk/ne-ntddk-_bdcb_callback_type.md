## Description

The BDCB_CALLBACK_TYPE enumeration specifies whether the callback being passed to a [BOOT_DRIVER_CALLBACK_FUNCTION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-ioregisterbootdrivercallback) routine is a status update or a boot-start driver initialization notification.

## Constants

### `BdCbStatusUpdate`

A status update provided by the system to a boot-start driver.

### `BdCbInitializeImage`

A boot image is about to be initialized. During this callback, boot-start drivers may classify a boot image as a known good image or a known bad image.

## Remarks

The two callback types have unique context structures that provide additional information specific to the callback.

| Value | Corresponding structure to use |
|--|--|
| BdCbStatusUpdate | [**BDCB_STATUS_UPDATE_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ne-ntddk-_bdcb_status_update_type) |
| BdCbInitializeImage | [**BDCB_CLASSIFICATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ne-ntddk-_bdcb_classification) |

## See also

[**BDCB_CLASSIFICATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ne-ntddk-_bdcb_classification)

[**BDCB_STATUS_UPDATE_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ne-ntddk-_bdcb_status_update_type)

[BOOT_DRIVER_CALLBACK_FUNCTION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nc-ntddk-boot_driver_callback_function)