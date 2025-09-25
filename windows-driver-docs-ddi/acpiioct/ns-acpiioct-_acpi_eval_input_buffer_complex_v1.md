# _ACPI_EVAL_INPUT_BUFFER_COMPLEX_V1 structure

## Description

The ACPI_EVAL_INPUT_BUFFER_COMPLEX structure is used as input to an [IOCTL_ACPI_EVAL_METHOD](https://learn.microsoft.com/windows-hardware/drivers/ddi/acpiioct/ni-acpiioct-ioctl_acpi_eval_method) request and to an [IOCTL_ACPI_ASYNC_EVAL_METHOD](https://learn.microsoft.com/windows-hardware/drivers/ddi/acpiioct/ni-acpiioct-ioctl_acpi_async_eval_method) request. The structure supplies the name of a control method and an input array of [ACPI_METHOD_ARGUMENT](https://learn.microsoft.com/windows-hardware/drivers/ddi/acpiioct/ns-acpiioct-_acpi_method_argument_v1) structures.

## Members

### `Signature`

The signature of a complex input buffer, which must be set to ACPI_EVAL_INPUT_BUFFER_COMPLEX_SIGNATURE.

### `DUMMYUNIONNAME`

### `DUMMYUNIONNAME.MethodName`

A four-element ASCII character array that contains the name of the method. For example, 'ABCD.'

### `DUMMYUNIONNAME.MethodNameAsUlong`

A value of type ULONG that contains the name of the method in the format (ULONG) ('DCBA'), where the method name is the four-element ASCII character array 'ABCD.'

### `Size`

The number of bytes that the **Argument** array contains.

### `ArgumentCount`

The number of variable-length ACPI_METHOD_ARGUMENT structures that the **Argument** array contains. The **Argument** array can hold a maximum of seven argument structures.

### `Argument`

An array of ACPI_METHOD_ARGUMENT structures.

## Remarks

If a device supports a control method named 'ABCD' that takes an array of arguments as input, a driver for the device can evaluate the method by sending an IOCTL_ACPI_EVAL_METHOD request or an IOCTL_ACPI_ASYNC_EVAL_METHOD request to the device and setting the members of the input ACPI_EVAL_INPUT_BUFFER_COMPLEX structure as follows:

* Set **Signature** to ACPI_EVAL_INPUT_BUFFER_COMPLEX_SIGNATURE.
* Set **MethodName** to 'ABCD' or **MethodNameAsUlong** to (ULONG)('DCBA').
* Set **Size** to the number of bytes in the **Argument** array.
* Set **Argument** count to the number of arguments in the **Argument** array.
* Set **Argument** to the array of ACPI_METHOD_ARGUMENT structures.

For more information about how to use this structure, see [Evaluating ACPI Control Methods](https://learn.microsoft.com/windows-hardware/drivers/acpi/evaluating-acpi-control-methods).

## See also

[ACPI_METHOD_ARGUMENT](https://learn.microsoft.com/windows-hardware/drivers/ddi/acpiioct/ns-acpiioct-_acpi_method_argument_v1)

[IOCTL_ACPI_ASYNC_EVAL_METHOD](https://learn.microsoft.com/windows-hardware/drivers/ddi/acpiioct/ni-acpiioct-ioctl_acpi_async_eval_method)

[IOCTL_ACPI_EVAL_METHOD](https://learn.microsoft.com/windows-hardware/drivers/ddi/acpiioct/ni-acpiioct-ioctl_acpi_eval_method)