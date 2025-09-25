# _ACPI_EVAL_OUTPUT_BUFFER_V1 structure

## Description

The **ACPI_EVAL_OUTPUT_BUFFER** structure contains output arguments from an ACPI control method.

## Members

### `Signature`

The signature of the output buffer, which must be set to ACPI_EVAL_OUTPUT_BUFFER_SIGNATURE.

### `Length`

The size, in bytes, of the output buffer. This size includes the storage for the **ACPI_EVAL_OUTPUT_BUFFER** structure at the start of the output buffer, plus any additional storage that might be required for data in the **Argument** array that extends past the end of the **ACPI_EVAL_OUTPUT_BUFFER** structure.

### `Count`

The number of [ACPI_METHOD_ARGUMENT](https://learn.microsoft.com/windows-hardware/drivers/ddi/acpiioct/ns-acpiioct-_acpi_method_argument_v1) structures that the **Argument** array contains.

### `Argument`

An array of **ACPI_METHOD_ARGUMENT** structures. For more information, see Remarks.

## Remarks

The following ACPI IOCTLs return output arguments from ACPI control methods in an **ACPI_EVAL_OUTPUT_BUFFER** structure:

[IOCTL_ACPI_ASYNC_EVAL_METHOD](https://learn.microsoft.com/windows-hardware/drivers/ddi/acpiioct/ni-acpiioct-ioctl_acpi_async_eval_method)

[IOCTL_ACPI_ASYNC_EVAL_METHOD_EX](https://learn.microsoft.com/windows-hardware/drivers/ddi/acpiioct/ni-acpiioct-ioctl_acpi_async_eval_method_ex)

[IOCTL_ACPI_EVAL_METHOD](https://learn.microsoft.com/windows-hardware/drivers/ddi/acpiioct/ni-acpiioct-ioctl_acpi_eval_method)

[IOCTL_ACPI_EVAL_METHOD_EX](https://learn.microsoft.com/windows-hardware/drivers/ddi/acpiioct/ni-acpiioct-ioctl_acpi_eval_method_ex)

Typically, the **Argument** member is the start of an array of one or more **ACPI_METHOD_ARGUMENT** structures. If the array contains more than one **ACPI_METHOD_ARGUMENT** structure, the additional structures follow the end of the **ACPI_EVAL_OUTPUT_BUFFER** structure. However, these **ACPI_METHOD_ARGUMENT** structures form a true array only if none of the **DataLength** members of these structures has a value greater than **sizeof**(ULONG). For some types of data, the **DataLength** value in one or more of these structures can be greater than **sizeof**(ULONG), in which case the offsets between adjacent **ACPI_METHOD_ARGUMENT** structures can vary.

For more information about how to use **ACPI_EVAL_OUTPUT_BUFFER** structures to retrieve output arguments from an ACPI control method, see [Evaluating ACPI Control Methods](https://learn.microsoft.com/windows-hardware/drivers/acpi/evaluating-acpi-control-methods).

## See also

[ACPI_METHOD_ARGUMENT](https://learn.microsoft.com/windows-hardware/drivers/ddi/acpiioct/ns-acpiioct-_acpi_method_argument_v1)