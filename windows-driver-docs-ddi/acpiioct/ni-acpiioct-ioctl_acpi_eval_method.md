# IOCTL_ACPI_EVAL_METHOD IOCTL

## Description

A driver for a device can use the IOCTL_ACPI_EVAL_METHOD device control request to synchronously evaluate an ACPI control method that is supported by the device. The driver should call [IoBuildDeviceIoControlRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iobuilddeviceiocontrolrequest) and pass the following input and output parameters to build this request.

## Parameters

### Major code

### Input buffer

Set the **IoBuildDeviceIoControlRequest** input parameters as follows:

* *IoControlCode* is set to IOCTL_ACPI_EVAL_METHOD.
* *DeviceObject* is set to a pointer to the physical device object (PDO) of the device.
* *InputBuffer* is set to a pointer to an input buffer structure that depends on the type of input arguments to be passed to the control method. For more information about the type of input arguments that this IOCTL supports, see the Remarks section later in this topic.
* *InputBufferLength* is set to the size, in bytes, of the input buffer that is supplied by *InputBuffer*.
* *OutputBufferLength* supplies the size, in bytes, of the output buffer that is supplied by *OutputBuffer*.
* *InternalDeviceIoControl* is set to **FALSE**.
* *Event* is set to a pointer to a caller-allocated and initialized event object.

### Input buffer length

*InputBufferLength* is set to the size, in bytes, of the input buffer that is supplied by *InputBuffer*.

### Output buffer

Set the **IoBuildDeviceIoControlRequest** output parameters as follows:

* *OutputBuffer* supplies a pointer to an [ACPI_EVAL_OUTPUT_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/acpiioct/ns-acpiioct-_acpi_eval_output_buffer_v1) structure that contains the output arguments from the control method.
* *IoStatusBlock* is set to an [IO_STATUS_BLOCK](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_io_status_block) structure.

### Output buffer length

*OutputBufferLength* supplies the size, in bytes, of the output buffer that is supplied by *OutputBuffer*.

### Input/output buffer

### Input/output buffer length

### Status block

If the request succeeds, *IoStatusBlock*->**Status** is set to STATUS_SUCCESS; otherwise, the **Status** member is set to an error code. If the output buffer is not large enough to contain the output buffer header, the **Status** member is set to STATUS_BUFFER_TOO_SMALL. If the output buffer is large enough to contain the output buffer header, but is not large enough to contain all the output arguments from the control method, the **Status** member is set to STATUS_BUFFER_OVERFLOW, and *OutputBuffer*->**Length** is set to the required length of the output buffer.

If the request succeeds, the *IoStatusBlock*->**Information** member is set to the number of bytes that is returned in the output buffer; otherwise, the **Information** member is set to zero.

## Remarks

A driver for a device can use IOCTL_ACPI_EVAL_METHOD to synchronously evaluate a control method that the device supports. For example, if the device is named 'ABCD' in an ACPI namespace and the 'ABCD' device supports a method named '_FOO,' this IOCTL can be used to evaluate control method '_FOO' by sending the sending the request to the 'ABCD' device and supplying the control method name '_FOO.'

IOCTL_ACPI_EVAL_METHOD supports the following types of input buffer structures:

[ACPI_EVAL_INPUT_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/acpiioct/ns-acpiioct-_acpi_eval_input_buffer_v1)

[ACPI_EVAL_INPUT_BUFFER_SIMPLE_INTEGER](https://learn.microsoft.com/windows-hardware/drivers/ddi/acpiioct/ns-acpiioct-_acpi_eval_input_buffer_simple_integer_v1)

[ACPI_EVAL_INPUT_BUFFER_SIMPLE_STRING](https://learn.microsoft.com/windows-hardware/drivers/ddi/acpiioct/ns-acpiioct-_acpi_eval_input_buffer_simple_string_v1)

[ACPI_EVAL_INPUT_BUFFER_COMPLEX](https://learn.microsoft.com/windows-hardware/drivers/ddi/acpiioct/ns-acpiioct-_acpi_eval_input_buffer_complex_v1)

The output arguments from the control method are returned in the variable-length [ACPI_EVAL_OUTPUT_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/acpiioct/ns-acpiioct-_acpi_eval_output_buffer_v1) structure that is supplied by the *OutBuffer* pointer. The ACPI_EVAL_OUTPUT_BUFFER includes an array of variable-length [ACPI_METHOD_ARGUMENT](https://learn.microsoft.com/windows-hardware/drivers/ddi/acpiioct/ns-acpiioct-_acpi_method_argument_v1) structures, each of which returns an output argument.

For more information about how to synchronously evaluate control methods, see [Evaluating ACPI Control Methods Synchronously](https://learn.microsoft.com/windows-hardware/drivers/acpi/evaluating-acpi-control-methods-synchronously).

Starting with Windows Server 2008 and Windows Vista, a driver can also use an [IOCTL_ACPI_EVAL_METHOD_EX](https://learn.microsoft.com/windows-hardware/drivers/ddi/acpiioct/ni-acpiioct-ioctl_acpi_eval_method_ex) request to synchronously evaluate a control method that is not an immediate child object of a device.

For information about how to evaluate an ACPI control method asynchronously starting on Windows Server 2008 and Windows Vista, see [IOCTL_ACPI_ASYNC_EVAL_METHOD](https://learn.microsoft.com/windows-hardware/drivers/ddi/acpiioct/ni-acpiioct-ioctl_acpi_async_eval_method) and [IOCTL_ACPI_ASYNC_EVAL_METHOD_EX](https://learn.microsoft.com/windows-hardware/drivers/ddi/acpiioct/ni-acpiioct-ioctl_acpi_async_eval_method_ex).

IOCTL_ACPI_EVAL_METHOD can be used only at IRQL < DISPATCH_LEVEL.

## See also

[ACPI_EVAL_INPUT_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/acpiioct/ns-acpiioct-_acpi_eval_input_buffer_v1)

[ACPI_EVAL_INPUT_BUFFER_COMPLEX](https://learn.microsoft.com/windows-hardware/drivers/ddi/acpiioct/ns-acpiioct-_acpi_eval_input_buffer_complex_v1)

[ACPI_EVAL_INPUT_BUFFER_SIMPLE_INTEGER](https://learn.microsoft.com/windows-hardware/drivers/ddi/acpiioct/ns-acpiioct-_acpi_eval_input_buffer_simple_integer_v1)

[ACPI_EVAL_INPUT_BUFFER_SIMPLE_STRING](https://learn.microsoft.com/windows-hardware/drivers/ddi/acpiioct/ns-acpiioct-_acpi_eval_input_buffer_simple_string_v1)

[ACPI_EVAL_OUTPUT_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/acpiioct/ns-acpiioct-_acpi_eval_output_buffer_v1)

[ACPI_METHOD_ARGUMENT](https://learn.microsoft.com/windows-hardware/drivers/ddi/acpiioct/ns-acpiioct-_acpi_method_argument_v1)

[IOCTL_ACPI_ASYNC_EVAL_METHOD](https://learn.microsoft.com/windows-hardware/drivers/ddi/acpiioct/ni-acpiioct-ioctl_acpi_async_eval_method)

[IOCTL_ACPI_ASYNC_EVAL_METHOD_EX](https://learn.microsoft.com/windows-hardware/drivers/ddi/acpiioct/ni-acpiioct-ioctl_acpi_async_eval_method_ex)

[IOCTL_ACPI_EVAL_METHOD_EX](https://learn.microsoft.com/windows-hardware/drivers/ddi/acpiioct/ni-acpiioct-ioctl_acpi_eval_method_ex)