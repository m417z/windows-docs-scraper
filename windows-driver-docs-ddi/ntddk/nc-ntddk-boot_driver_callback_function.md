# BOOT_DRIVER_CALLBACK_FUNCTION callback function

## Description

A boot-start driver's BOOT_DRIVER_CALLBACK_FUNCTION routine can monitor boot-start driver initialization events and return data to the kernel to enable the kernel to decide whether to initialize each boot-start driver. The function prototype to register a boot-start driver callback routine is as follows.

## Parameters

### `CallbackContext`

The value that the driver passed as the _CallbackContext_ parameter to [**IoRegisterBootDriverCallback**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-ioregisterbootdrivercallback) when it registered this BOOT_DRIVER_CALLBACK_FUNCTION implementation.

### `Classification`

A [**BDCB_CALLBACK_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ne-ntddk-_bdcb_callback_type) enumeration value that either identifies the status of boot-start driver initialization or indicates that a boot-start driver is about to be initialized.

### `ImageInformation`

A pointer to a [**BDCB_IMAGE_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_bdcb_image_information) structure that contains information that is specific to the type of callback. The structure type depends on the value passed for CallbackType, as shown in the following table.

| Value of CallbackType | Corresponding structure to use |
| --------------------- | ------------------------------ |
| BdCbStatusUpdate | BDCB_STATUS_UPDATE_TYPE |
| BdCbInitializeImage | BDCB_CLASSIFICATION |

## Remarks

To be notified of boot-start driver initialization operations, an early launch anti-malware (ELAM) driver can call [**IoRegisterBootDriverCallback**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-ioregisterbootdrivercallback). To unregister, call [**IoUnRegisterBootDriverCallback**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-iounregisterbootdrivercallback).

## See also

[**IoRegisterBootDriverCallback**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-ioregisterbootdrivercallback)

[**IoUnregisterBootDriverCallback**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-iounregisterbootdrivercallback)