# _PEP_ACPI_EVALUATE_CONTROL_METHOD structure (pep_x.h)

## Description

The **PEP_ACPI_EVALUATE_CONTROL_METHOD** structure specifies an ACPI control method to evaluate, an input argument to supply to this method, and an output buffer for the result of the evaluation.

## Members

### `DeviceHandle`

A PEPHANDLE value that identifies the device's registration for ACPI services. The platform extension plug-in (PEP) supplied this handle in response to a previous [PEP_NOTIFY_ACPI_REGISTER_DEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_acpi_register_device) notification.

### `RequestFlags`

A set of flags. This member contains one of the following values.

| Flag name | Value | Meaning |
|--|--|--|
| PEP_ACPI_ECM_FLAG_NONE | 0x0 | Not a valid control method name. |
| PEP_ACPI_ECM_FLAG_RELATIVE_NAME | 0x1 | The **MethodNameUlong** member contains a path-relative control method name. |
| PEP_ACPI_ECM_FLAG_FULLY_QUALIFIED_NAME | 0x2 | The **MethodNameString** member contains a fully qualified control method name. |

### `MethodName`

A ULONG value that contains the four-character, path-relative name of the ACPI control method.

### `MethodNameString`

An [ANSI_STRING](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-string) structure that contains the fully qualified name of the ACPI control method. This name specifies the path and name of the method in the ACPI namespace. For more information, see [Enumerating Child Devices and Control Methods](https://learn.microsoft.com/windows-hardware/drivers/acpi/enumerating-child-devices-and-control-methods).

### `MethodStatus`

An NTSTATUS value that indicates the status of the evaluation of the ACPI control method. Set this member to STATUS_SUCCESS to indicate that the platform extension plug-in (PEP) successfully completed its evaluation of the method. Set to STATUS_NOT_SUPPORTED to indicate that the PEP does not recognize the control method. Set to STATUS_BUFFER_TOO_SMALL to indicate that the output buffer size specified by the **InputArgumentSize** member is not large enough to contain the method results.

If the PEP is to evaluate the method asynchronously, set this member to STATUS_PENDING and return from the [AcceptAcpiNotification](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/nc-pepfx-pepcallbacknotifyacpi) callback. Later, when the evaluation is completed, the PEP calls the *CompleteWork* routine to notify the Windows [power management framework](https://learn.microsoft.com/windows-hardware/drivers/ddi/_kernel/#device-power-management) (PoFx) that the evaluation of the control method is complete.

### `CompletionContext`

A pointer to a completion context value. The PEP uses this member only if the control method is evaluated asynchronously. In this case, the PEP supplies this completion context pointer in the call to the *CompleteWork* routine that notifies the Windows [power management framework](https://learn.microsoft.com/windows-hardware/drivers/ddi/_kernel/#device-power-management) (PoFx) that the evaluation of the control method is complete. Included in the input parameters to this call is a pointer to a [PEP_WORK_ACPI_EVALUATE_CONTROL_METHOD_COMPLETE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_work_acpi_evaluate_control_method_complete) structure to which the PEP has written the completion context pointer. The context is opaque to the PEP and contains data used internally by PoFx.

### `InputArgumentCount`

The number of input arguments in the input buffer pointed to by the **InputArguments** member. Each argument starts with an [ACPI_METHOD_ARGUMENT](https://learn.microsoft.com/windows-hardware/drivers/ddi/acpiioct/ns-acpiioct-_acpi_method_argument_v1) structure that specifies the size of the argument. Currently, the maximum **InputArgumentCount** value is one.

### `InputArgumentSize`

The size, in bytes, of the input buffer pointed to by the **InputArguments** member.

### `InputArguments`

A pointer to an input buffer that contains an [ACPI_METHOD_ARGUMENT](https://learn.microsoft.com/windows-hardware/drivers/ddi/acpiioct/ns-acpiioct-_acpi_method_argument_v1) structure that specifies the input argument for the specified ACPI control method.

### `OutputArgumentCount`

The number of output arguments in the output buffer pointed to by the **OutputArguments** member. Each argument starts with an [ACPI_METHOD_ARGUMENT](https://learn.microsoft.com/windows-hardware/drivers/ddi/acpiioct/ns-acpiioct-_acpi_method_argument_v1) structure that specifies the size of the argument. Currently, the maximum allowed **OutputArgumentCount** value is one.

### `OutputArgumentSize`

On input, the size, in bytes, of the output buffer pointed to by the **OutputArguments** member. If this buffer is not large enough to contain the result of evaluating the method, the PEP overwrites the **OutputArgumentSize** input value with the required size, and sets the **MethodStatus** member to STATUS_BUFFER_TOO_SMALL.

### `OutputArguments`

A pointer to an output buffer to which the PEP writes an [ACPI_METHOD_ARGUMENT](https://learn.microsoft.com/windows-hardware/drivers/ddi/acpiioct/ns-acpiioct-_acpi_method_argument_v1) structure that contains the result of evaluating the specified ACPI control method.

## Remarks

This structure is used by the [PEP_NOTIFY_ACPI_EVALUATE_CONTROL_METHOD](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_acpi_evaluate_control_method) notification. The **MethodStatus** member contains an output value that the PEP writes to the structure in response to this notification. The **OutputArgumentSize** member contains an input value supplied by PoFx when the notification is sent. The PEP may overwrite this input value with an output value if the input value is less than the required output buffer size. All other members of this structure contain input values that are supplied by PoFx when the notification is sent.

This structure defines an unnamed union that contains either the four-character path-relative control method name (if **RequestFlags** = PEP_ACPI_ECM_FLAG_RELATIVE_NAME) or the fully qualified control method name (if **RequestFlags** = PEP_ACPI_ECM_FLAG_FULLY_QUALIFIED_NAME).

## See also

- [ACPI_METHOD_ARGUMENT](https://learn.microsoft.com/windows-hardware/drivers/ddi/acpiioct/ns-acpiioct-_acpi_method_argument_v1)
- [ANSI_STRING](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-string)
- [PEP_NOTIFY_ACPI_EVALUATE_CONTROL_METHOD](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_acpi_evaluate_control_method)
- [PEP_NOTIFY_ACPI_REGISTER_DEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_acpi_register_device)