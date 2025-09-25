# _ACPI_EVAL_INPUT_BUFFER_SIMPLE_INTEGER_V1 structure

## Description

The ACPI_EVAL_INPUT_BUFFER_SIMPLE_INTEGER structure is used as input to an [IOCTL_ACPI_EVAL_METHOD](https://learn.microsoft.com/windows-hardware/drivers/ddi/acpiioct/ni-acpiioct-ioctl_acpi_eval_method) request and to an [IOCTL_ACPI_ASYNC_EVAL_METHOD](https://learn.microsoft.com/windows-hardware/drivers/ddi/acpiioct/ni-acpiioct-ioctl_acpi_async_eval_method) request. The structure supplies the name of a control method and an input argument of type ULONG.

## Members

### `Signature`

The signature of an integer input buffer, which must be set to ACPI_EVAL_INPUT_BUFFER_SIMPLE_INTEGER_SIGNATURE.

### `DUMMYUNIONNAME`

### `DUMMYUNIONNAME.MethodName`

A four-element ASCII character array that contains the name of a control method, for example, 'ABCD.'

### `DUMMYUNIONNAME.MethodNameAsUlong`

A value of type ULONG that contains the name of the method in the format (ULONG) ('DCBA'), where the method name is the four-element ASCII character array 'ABCD.'

### `IntegerArgument`

An argument value of type ULONG that is passed as input to the control method.

## Remarks

If a device supports a control method named ABCD that takes one integer argument of type ULONG, a driver for the device can evaluate the method by sending an IOCTL_EVAL_METHOD request or an IOCTL_ACPI_ASYNC_EVAL_METHOD request to the device and setting the members of the input ACPI_EVAL_INPUT_BUFFER structure as follows:

* Set **Signature** to ACPI_EVAL_INPUT_BUFFER_SIMPLE_INTEGER_SIGNATURE.
* Set **MethodName** to 'ABCD' or **MethodNameAsUlong** to (ULONG)('DCBA').
* Set **IntegerArgument** to the input integer value.

For more information about how to use this structure, see [Evaluating ACPI Control Methods](https://learn.microsoft.com/windows-hardware/drivers/acpi/evaluating-acpi-control-methods).

## See also

[IOCTL_ACPI_ASYNC_EVAL_METHOD](https://learn.microsoft.com/windows-hardware/drivers/ddi/acpiioct/ni-acpiioct-ioctl_acpi_async_eval_method)

[IOCTL_ACPI_EVAL_METHOD](https://learn.microsoft.com/windows-hardware/drivers/ddi/acpiioct/ni-acpiioct-ioctl_acpi_eval_method)