# POFXCALLBACKENUMERATEUNMASKEDINTERRUPTS callback function (pep_x.h)

## Description

The **EnumerateUnmaskedInterrupts** routine enumerates interrupt sources whose interrupts are unmasked and enabled.

## Parameters

### `PluginHandle` [in, optional]

A POHANDLE value. If non-NULL, this parameter is a handle that identifies the platform extension plug-in (PEP), in which case **EnumerateUnmaskedInterrupts** enumerates only interrupts that are managed by this PEP. If this parameter is NULL, **EnumerateUnmaskedInterrupts** enumerates *all* interrupts in the hardware platform that are unmasked and enabled.

### `EnumerateFlags` [in, optional]

No flags are currently defined. Set this parameter to PEP_ENUMERATE_UNMASKED_INTERRUPT_FLAGS_NONE (0x0).

### `Callback` [in]

A pointer to a caller-implemented [EnumerateInterruptSource](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/nc-pepfx-ppo_enumerate_interrupt_source_callback) callback routine. This callback routine is called once for each interrupt source whose interrupt is unmasked. These callbacks occur synchronously before the **EnumerateUnmaskedInterrupts** routine returns.

### `CallbackContext` [in]

A pointer to a callback context. This pointer is passed as a parameter to the *EnumerateInterruptSource* callback routine pointed to by the *Callback* parameter. The contents of the callback context are PEP-defined, and are opaque to the [power management framework](https://learn.microsoft.com/windows-hardware/drivers/ddi/_kernel/#device-power-management) (PoFx).

### `InterruptInformation` [in, out]

A pointer to a caller-allocated buffer whose size is at least **sizeof**([PEP_UNMASKED_INTERRUPT_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_unmasked_interrupt_information)) bytes. **EnumerateUnmaskedInterrupts** will use this buffer to transfer interrupt information to the PEP during calls to the PEP's *EnumerateInterruptSource* callback routine.

## Return value

**EnumerateUnmaskedInterrupts** returns STATUS_SUCCESS if the call successfully enumerates the interrupts. Possible error return values include the following status code.

| Return value | Description |
| --- | --- |
| STATUS_INVALID_PARAMETER | The **Size** or **Version** member of the **PEP_UNMASKED_INTERRUPT_INFORMATION** structure contains an invalid value. |

## Remarks

This routine is implemented by PoFx and is called by the PEP. The **EnumerateUnmaskedInterrupts** member of the [PEP_KERNEL_INFORMATION_STRUCT_V3](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_kernel_information_struct_v3) structure is a pointer to an **EnumerateUnmaskedInterrupts** routine.

Before the platform enters a system power state in which the interrupt controllers are power-gated, the PEP can call **EnumerateUnmaskedInterrupts** to get the information it needs to properly configure wake-up controllers for interrupts that are to remain unmasked.

The PEP can call this routine at IRQL <= HIGH_LEVEL.

## See also

[EnumerateInterruptSource](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/nc-pepfx-ppo_enumerate_interrupt_source_callback)

[PEP_KERNEL_INFORMATION_STRUCT_V3](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_kernel_information_struct_v3)

[PEP_UNMASKED_INTERRUPT_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_unmasked_interrupt_information)