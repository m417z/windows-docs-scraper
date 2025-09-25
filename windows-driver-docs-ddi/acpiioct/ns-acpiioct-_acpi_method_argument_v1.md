# _ACPI_METHOD_ARGUMENT_V1 structure

## Description

The ACPI_METHOD_ARGUMENT structure contains the value of an input or output argument of an ACPI control method.

## Members

### `Type`

The type of the method argument, as specified by one of the following:

#### ACPI_METHOD_ARGUMENT_INTEGER

**Argument** contains an integer value of type ULONG.

#### ACPI_METHOD_ARGUMENT_STRING

The **Data** array contains a NULL-terminated ASCII string, and **DataLength** supplies the number of characters in the string, including the NULL terminator.

#### ACPI_METHOD_ARGUMENT_BUFFER

The **Data** array contains custom data, and **DataLength** supplies the number of consecutive array elements that contain the custom data, beginning with the **Data**[0] element.

#### ACPI_METHOD_ARGUMENT_PACKAGE

The **Data** array contains an ACPI package descriptor and **DataLength** supplies the number of consecutive array elements that contain the package descriptor, beginning with the **Data**[0] element.

### `DataLength`

The number of UCHAR elements in the **Data** array that contains the argument data.

### `DUMMYUNIONNAME`

### `DUMMYUNIONNAME.Argument`

An argument value of type ULONG.

### `DUMMYUNIONNAME.Data`

An array of values of type UCHAR that contains argument data.

## Remarks

An ACPI_EVAL_OUTPUT_BUFFER structure includes an **Argument** array of ACPI_METHOD_ARGUMENT structures. The following IOCTLs evaluate control methods and return output arguments in an [ACPI_EVAL_OUTPUT_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/acpiioct/ns-acpiioct-_acpi_eval_output_buffer_v1) structure:

[IOCTL_ACPI_ASYNC_EVAL_METHOD](https://learn.microsoft.com/windows-hardware/drivers/ddi/acpiioct/ni-acpiioct-ioctl_acpi_async_eval_method)

[IOCTL_ACPI_ASYNC_EVAL_METHOD_EX](https://learn.microsoft.com/windows-hardware/drivers/ddi/acpiioct/ni-acpiioct-ioctl_acpi_async_eval_method_ex)

[IOCTL_ACPI_EVAL_METHOD](https://learn.microsoft.com/windows-hardware/drivers/ddi/acpiioct/ni-acpiioct-ioctl_acpi_eval_method)

[IOCTL_ACPI_EVAL_METHOD_EX](https://learn.microsoft.com/windows-hardware/drivers/ddi/acpiioct/ni-acpiioct-ioctl_acpi_eval_method_ex)

The ACPI_METHOD_ARGUMENT structure is also used to supply an array of complex input arguments to a control method. The [ACPI_EVAL_INPUT_BUFFER_COMPLEX](https://learn.microsoft.com/windows-hardware/drivers/ddi/acpiioct/ns-acpiioct-_acpi_eval_input_buffer_complex_v1) and [ACPI_EVAL_INPUT_BUFFER_COMPLEX_EX](https://learn.microsoft.com/windows-hardware/drivers/ddi/acpiioct/ns-acpiioct-_acpi_eval_input_buffer_complex_v1_ex) structures includes an **Argument** array of type ACPI_METHOD_ARGUMENT.

For more information about how to use ACPI_METHOD_ARGUMENT structures to supply and retrieve argument data to an ACPI control method, see [Evaluating ACPI Control Methods](https://learn.microsoft.com/windows-hardware/drivers/acpi/evaluating-acpi-control-methods).

## See also

[ACPI_EVAL_INPUT_BUFFER_COMPLEX](https://learn.microsoft.com/windows-hardware/drivers/ddi/acpiioct/ns-acpiioct-_acpi_eval_input_buffer_complex_v1)

[ACPI_EVAL_INPUT_BUFFER_COMPLEX_EX](https://learn.microsoft.com/windows-hardware/drivers/ddi/acpiioct/ns-acpiioct-_acpi_eval_input_buffer_complex_v1_ex)

[ACPI_EVAL_OUTPUT_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/acpiioct/ns-acpiioct-_acpi_eval_output_buffer_v1)