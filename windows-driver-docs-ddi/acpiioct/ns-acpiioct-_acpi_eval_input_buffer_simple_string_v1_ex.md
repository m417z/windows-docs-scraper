# _ACPI_EVAL_INPUT_BUFFER_SIMPLE_STRING_V1_EX structure

## Description

The ACPI_EVAL_INPUT_BUFFER_SIMPLE_STRING_EX structure is used as input to an [IOCTL_ACPI_EVAL_METHOD_EX](https://learn.microsoft.com/windows-hardware/drivers/ddi/acpiioct/ni-acpiioct-ioctl_acpi_eval_method_ex) request and to an [IOCTL_ACPI_ASYNC_EVAL_METHOD_EX](https://learn.microsoft.com/windows-hardware/drivers/ddi/acpiioct/ni-acpiioct-ioctl_acpi_async_eval_method_ex) request. The structure supplies the path and name of a control method in an ACPI namespace and an input argument that is an ASCII string.

## Members

### `Signature`

The signature of an extended string input buffer that must be set to ACPI_EVAL_INPUT_BUFFER_SIMPLE_STRING_SIGNATURE_EX.

### `MethodName`

A NULL-terminated ASCII string that contains the path and name of a control method in an ACPI namespace. The maximum number of characters that the string can contain, including a NULL terminator, is 256. For more information about how to supply the path and name of a control method, see the Remarks section later in this topic.

### `StringLength`

The number of ASCII characters in the array of characters that is supplied by **String**.

### `String`

An ASCII character array that contains the number of characters that is specified by **StringLength**. The character array does not include a NULL terminator.

## Remarks

A driver for a device can use an IOCTL_ACPI_EVAL_METHOD_EX request or an IOCTL_ACPI_ASYNC_EVAL_METHOD_EX request to evaluate a control method that is a descendant child object of the device. If the method takes a single string input argument, these requests take an input ACPI_EVAL_INPUT_BUFFER_STRING_EX structure as follows:

* Set **Signature** to ACPI_EVAL_INPUT_BUFFER_SIMPLE_STRING_SIGNATURE_EX.
* Set **MethodName** to a NULL-terminated string that supplies either the full path and name to a control method in the ACPI namespace or the path and name of the method that is relative to the device to which the evaluation request is sent.

  For example, assume that a request is sent to a device named 'ABCD,' which is an immediate child of the root of an ACPI namespace, that 'ABCD' device supports a child device named 'CHLD,' and that the 'CHLD' device supports a method named '_FOO.' In this case, the evaluation request can supply either '\ABCD.CHLD._FOO,' which is the fully qualified path and name of the control method in the ACPI namespace, or 'CHLD._FOO,' which is the path and name of the control method that is relative to the 'ABCD' device in the ACPI namespace.

  For more information about how to obtain the fully qualified path and name of a control method in an ACPI namespace, see [Enumerating Child Devices and Control Methods](https://learn.microsoft.com/windows-hardware/drivers/acpi/enumerating-child-devices-and-control-methods).
* Set **StringLength** to the number of characters in **String**.
* Set **String** to the input string.

For more information about how to use this structure, see [Evaluating ACPI Control Methods](https://learn.microsoft.com/windows-hardware/drivers/acpi/evaluating-acpi-control-methods).

## See also

[IOCTL_ACPI_ASYNC_EVAL_METHOD_EX](https://learn.microsoft.com/windows-hardware/drivers/ddi/acpiioct/ni-acpiioct-ioctl_acpi_async_eval_method_ex)

[IOCTL_ACPI_EVAL_METHOD_EX](https://learn.microsoft.com/windows-hardware/drivers/ddi/acpiioct/ni-acpiioct-ioctl_acpi_eval_method_ex)