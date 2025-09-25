# IoRegisterBootDriverCallback function

## Description

The **IoRegisterBootDriverCallback** routine registers a **[**BOOT_DRIVER_CALLBACK_FUNCTION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nc-ntddk-boot_driver_callback_function)** routine to be called during the initialization of a boot-start driver and its dependent DLLs.

## Parameters

### `CallbackFunction` [in]

A pointer to the **[**BOOT_DRIVER_CALLBACK_FUNCTION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nc-ntddk-boot_driver_callback_function)** routine to be called when initializing a boot-start driver or DLL.

### `CallbackContext` [in, optional]

A driver-defined context to be passed to the **[**BOOT_DRIVER_CALLBACK_FUNCTION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nc-ntddk-boot_driver_callback_function)** routine pointed to by *CallbackFunction*.

## Return value

A handle that represents the registration. This handle must be supplied as an input parameter in the call to the [IoUnRegisterBootDriverCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-iounregisterbootdrivercallback) routine that unregisters the **[**BOOT_DRIVER_CALLBACK_FUNCTION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nc-ntddk-boot_driver_callback_function)** routine.

## Remarks

Boot-start drivers must call [IoUnRegisterBootDriverCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-iounregisterbootdrivercallback) and pass the returned handle to unregister the boot-start driver callback before Windows unloads them.

Any error returned from a status update callback is treated as fatal and leads to a system bug check. Additionally, if an initialize image callback returns an error, the driver's image is treated as unknown.
To be notified of boot-start driver initialization operations, an *early launch anti-malware* (ELAM) driver can call **IoRegisterBootDriverCallback** to register a **[**BOOT_DRIVER_CALLBACK_FUNCTION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nc-ntddk-boot_driver_callback_function)** routine.

## See also

[BDCB_CALLBACK_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ne-ntddk-_bdcb_callback_type)

[BDCB_IMAGE_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_bdcb_image_information)

[IoUnRegisterBootDriverCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-iounregisterbootdrivercallback)