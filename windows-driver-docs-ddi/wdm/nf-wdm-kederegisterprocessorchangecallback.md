# KeDeregisterProcessorChangeCallback function

## Description

The **KeDeregisterProcessorChangeCallback** routine unregisters a callback function that was previously registered with the operating system by calling the [KeRegisterProcessorChangeCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keregisterprocessorchangecallback) routine.

## Parameters

### `CallbackHandle` [in]

The callback registration handle that was returned by the [KeRegisterProcessorChangeCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keregisterprocessorchangecallback) routine when the callback function was registered with the operating system.

## Remarks

A device driver calls the [KeRegisterProcessorChangeCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keregisterprocessorchangecallback) routine to register a callback function with the operating system so that the operating system will notify the driver when a new processor is added to the hardware partition. When the device driver no longer needs to receive notification when new processors are added to the hardware partition, it calls the **KeDeregisterProcessorChangeCallback** routine to unregister the callback function. A callback function that has been registered for notification of processor changes must be unregistered before the device driver is unloaded from the operating system.

## See also

[KeRegisterProcessorChangeCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keregisterprocessorchangecallback)