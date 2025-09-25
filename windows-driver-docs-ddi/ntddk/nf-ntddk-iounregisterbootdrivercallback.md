# IoUnregisterBootDriverCallback function

## Description

The **IoUnRegisterBootDriverCallback** routine unregisters a previously registered **[**BOOT_DRIVER_CALLBACK_FUNCTION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nc-ntddk-boot_driver_callback_function)** routine.

## Parameters

### `CallbackHandle` [in]

A handle returned from a previous call to [IoRegisterBootDriverCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-ioregisterbootdrivercallback).

## Remarks

A driver that calls [IoRegisterBootDriverCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-ioregisterbootdrivercallback) must call **IoUnRegisterBootDriverCallback** before being unloaded.

## See also

[IoRegisterBootDriverCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-ioregisterbootdrivercallback)