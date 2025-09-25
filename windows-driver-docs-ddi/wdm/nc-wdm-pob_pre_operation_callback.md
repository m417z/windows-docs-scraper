# POB_PRE_OPERATION_CALLBACK callback function

## Description

The *ObjectPreCallback* routine is called by the operating system when a process or thread handle operation occurs.

> [!WARNING]
> The actions that you can perform in this callback are restricted for safe calls. For more info, see [Windows Kernel-Mode Process and Thread Manager](https://learn.microsoft.com/windows-hardware/drivers/kernel/windows-kernel-mode-process-and-thread-manager).

## Parameters

### `RegistrationContext` [in]

The context that the driver specifies as the *CallBackRegistration*->**RegistrationContext** parameter of the [ObRegisterCallbacks](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-obregistercallbacks) routine. The meaning of this value is driver-defined.

### `OperationInformation` [in]

A pointer to an [OB_PRE_OPERATION_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_ob_pre_operation_information) structure that specifies the parameters of the handle operation.

## Return value

*ObjectPreCallback* returns an OB_PREOP_CALLBACK_STATUS value. Drivers must return OB_PREOP_SUCCESS.

## Remarks

Use the [ObRegisterCallbacks](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-obregistercallbacks) routine to register an *ObjectPreCallback* routine, and use the [ObUnRegisterCallbacks](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-obunregistercallbacks) routine to unregister the routine.

This routine is called at PASSIVE_LEVEL in an arbitrary thread context with normal kernel APCs disabled. Special kernel APCs are not disabled. For more information about APCs, see [Types of APCs](https://learn.microsoft.com/windows-hardware/drivers/kernel/types-of-apcs).

## See also

[OB_PRE_OPERATION_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_ob_pre_operation_information)

[ObRegisterCallbacks](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-obregistercallbacks)

[ObUnRegisterCallbacks](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-obunregistercallbacks)

[ObjectPostCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pob_post_operation_callback)