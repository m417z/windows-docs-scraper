# _ACPI_EVAL_INPUT_BUFFER_SIMPLE_STRING_V1 structure

## Description

The ACPI_EVAL_INPUT_BUFFER_SIMPLE_STRING structure is used as input to an [IOCTL_ACPI_EVAL_METHOD](https://learn.microsoft.com/windows-hardware/drivers/ddi/acpiioct/ni-acpiioct-ioctl_acpi_eval_method) request and to an [IOCTL_ACPI_ASYNC_EVAL_METHOD](https://learn.microsoft.com/windows-hardware/drivers/ddi/acpiioct/ni-acpiioct-ioctl_acpi_async_eval_method) request. The structure supplies the name of a control method and an input argument that is an ASCII string.

## Members

### `Signature`

The signature of a string input buffer, which must be set to ACPI_EVAL_INPUT_BUFFER_SIMPLE_STRING_SIGNATURE.

### `DUMMYUNIONNAME`

### `DUMMYUNIONNAME.MethodName`

This union member is a four-element ASCII character array that contains the name of the method. For example, 'ABCD.'

### `DUMMYUNIONNAME.MethodNameAsUlong`

This union member is a ULONG-typed variable that contains the name of the method in the format (ULONG) ('DCBA'), where the method name is the four-element ASCII character array 'ABCD.'

### `StringLength`

The number of ASCII characters in the array of characters that is supplied by **String**.

### `String`

An ASCII character string that contains the number of characters that is specified by **StringLength**. The string does not include a NULL terminator.

## Remarks

If a device supports a control method named ABCD that takes an ASCII string as input, a driver for the device can evaluate the method by sending an IOCTL_ACPI_EVAL_METHOD request or an IOCTL_ACPI_ASYNC_EVAL_METHOD request to the device and setting the members of the input ACPI_EVAL_INPUT_BUFFER structure as follows:

* Set **Signature** to ACPI_EVAL_INPUT_BUFFER_SIMPLE_STRING_SIGNATURE.
* Set **MethodName** to 'ABCD' or **MethodNameAsUlong** to (ULONG)('DCBA').
* Set **StringLength** to the number of characters that is supplied by **String**.
* Set **String** to the input string.

For more information about how to use this structure, see [Evaluating ACPI Control Methods](https://learn.microsoft.com/windows-hardware/drivers/acpi/evaluating-acpi-control-methods).

## See also

[IOCTL_ACPI_ASYNC_EVAL_METHOD](https://learn.microsoft.com/windows-hardware/drivers/ddi/acpiioct/ni-acpiioct-ioctl_acpi_async_eval_method)

[IOCTL_ACPI_EVAL_METHOD](https://learn.microsoft.com/windows-hardware/drivers/ddi/acpiioct/ni-acpiioct-ioctl_acpi_eval_method)