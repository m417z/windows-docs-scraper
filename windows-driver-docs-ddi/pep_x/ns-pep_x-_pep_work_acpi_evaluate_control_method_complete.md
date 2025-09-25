# _PEP_WORK_ACPI_EVALUATE_CONTROL_METHOD_COMPLETE structure (pep_x.h)

## Description

The **PEP_WORK_ACPI_EVALUATE_CONTROL_METHOD_COMPLETE** structure contains the results of an ACPI control method that was asynchronously evaluated by the platform extension plug-in (PEP).

## Members

### `DeviceHandle`

A POHANDLE value that represents the registration of the device with the Windows [power management framework](https://learn.microsoft.com/windows-hardware/drivers/ddi/_kernel/#device-power-management) (PoFx). The PEP previously received this handle from PoFx during the [PEP_NOTIFY_ACPI_REGISTER_DEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_acpi_register_device) notification in which the PEP elected to provide ACPI services for the device.

### `CompletionFlags`

A set of completion flags. No flags are currently defined for this member, which is always set to PEP_ACPI_EVALUATE_CONTROL_METHOD_COMPLETE_FLAG_NONE (0x0).

### `MethodStatus`

### `CompletionContext`

A pointer to a completion context value. This is the same pointer that PoFx passed to the PEP in the [PEP_NOTIFY_ACPI_EVALUATE_CONTROL_METHOD](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_acpi_evaluate_control_method) notification that initiated the asynchronous evaluation of the ACPI control method.

### `OutputArgumentSize`

The size, in bytes, of the buffer pointed to by the **OutputArguments** member.

### `OutputArguments`

A pointer to a buffer to which the PEP has written the result of evaluating the ACPI control method. This buffer starts with a [ACPI_METHOD_ARGUMENT](https://learn.microsoft.com/windows-hardware/drivers/ddi/acpiioct/ns-acpiioct-_acpi_method_argument_v1) structure, which might be followed by additional output data. PoFx allocated this buffer and passed the buffer pointer to the PEP in the [PEP_NOTIFY_ACPI_EVALUATE_CONTROL_METHOD](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_acpi_evaluate_control_method) notification that initiated the asynchronous evaluation of the ACPI control method.

## Remarks

The **ControlMethodComplete** member of the [PEP_WORK_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_work_information) structure is a **PEP_WORK_ACPI_EVALUATE_CONTROL_METHOD_COMPLETE** structure.

A **PEP_WORK_INFORMATION** structure is included in the input parameters to the *CompleteWork* routine. The PEP writes the control method results to the **ControlMethodComplete** member of this structure before calling the routine. Evaluation of the control method was initiated by a previous [PEP_NOTIFY_ACPI_EVALUATE_CONTROL_METHOD](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_acpi_evaluate_control_method) notification.

## See also

[ACPI_METHOD_ARGUMENT](https://learn.microsoft.com/windows-hardware/drivers/ddi/acpiioct/ns-acpiioct-_acpi_method_argument_v1)

[PEP_NOTIFY_ACPI_EVALUATE_CONTROL_METHOD](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_acpi_evaluate_control_method)

[PEP_NOTIFY_ACPI_REGISTER_DEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_acpi_register_device)

[PEP_WORK_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_work_information)