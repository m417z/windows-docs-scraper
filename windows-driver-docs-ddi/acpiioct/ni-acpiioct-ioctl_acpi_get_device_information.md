# IOCTL_ACPI_GET_DEVICE_INFORMATION IOCTL

## Description

A driver for a device can use the IOCTL_ACPI_GET_DEVICE_INFORMATION device control request to obtain fine-grained identification information about its device. This IOCTL is typically used by drivers that support multiple versions or revisions of a device, and need to examine the component parts that make up the device's HW ID string to identify the exact device. The driver should call [IoBuildDeviceIoControlRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iobuilddeviceiocontrolrequest) and pass the following input and output parameters to build this request.

## Parameters

### Major code

### Input buffer

Set the **IoBuildDeviceIoControlRequest** input parameters as follows:

* *IoControlCode* is set to IOCTL_ACPI_GET_DEVICE_INFORMATION.
* *DeviceObject* is set to a pointer to the physical device object (PDO) of the device.
* *InputBuffer* is set to a pointer to an input buffer structure that depends on the type of input arguments to be passed to the control method. For more information about the type of input arguments that this IOCTL supports, see the Remarks section later in this topic.
* *InputBufferLength* is set to the size, in bytes, of the input buffer that is supplied by *InputBuffer*.
* *OutputBufferLength* supplies the size, in bytes, of the output buffer that is supplied by *OutputBuffer*.
* *InternalDeviceIoControl* is set to **FALSE**.
* *Event* is set to **NULL**.

### Input buffer length

*InputBufferLength* is set to the size, in bytes, of the input buffer that is supplied by *InputBuffer*.

### Output buffer

Set the **IoBuildDeviceIoControlRequest** output parameters as follows:

* *OutputBuffer* supplies a pointer to an [ACPI_DEVICE_INFORMATION_OUTPUT_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/acpiioct/ns-acpiioct-_acpi_device_information_output_buffer) structure that contains the output arguments from the control method.
* *IoStatusBlock* is set to an [IO_STATUS_BLOCK](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_io_status_block) structure.

### Output buffer length

*OutputBufferLength* supplies the size, in bytes, of the output buffer that is supplied by *OutputBuffer*.

### Input/output buffer

### Input/output buffer length

### Status block

If the request succeeds, *IoStatusBlock*->**Status** is set to STATUS_SUCCESS; otherwise, the **Status** member is set to an error code. If the output buffer is not large enough to contain the output buffer header, the **Status** member is set to STATUS_BUFFER_TOO_SMALL. If the output buffer is large enough to contain the output buffer header, but is not large enough to contain all the output arguments from the control method, the **Status** member is set to STATUS_BUFFER_OVERFLOW, and *OutputBuffer*->**Length** is set to the required length of the output buffer.

If the request succeeds, the *IoStatusBlock*->**Information** member is set to the number of bytes that is returned in the output buffer; otherwise, the **Information** member is set to zero.

## Remarks

A driver for a device can use IOCTL_ACPI_GET_DEVICE_INFORMATION to obtain fine-grained identification information about its device. This IOCTL is typically used with drivers that support multiple hardware versions or revisions of a device, and need to examine the component parts that make up the device's HW ID string to identify the exact device. For example, a driver may support different revisions of the same device, in which some aspect of the programing interface or the device's behavior is different. The driver can identify exactly which revision it is running on.

The output arguments from the request are returned in the variable-length [ACPI_DEVICE_INFORMATION_OUTPUT_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/acpiioct/ns-acpiioct-_acpi_device_information_output_buffer) structure that is supplied by the *OutBuffer* pointer. The ACPI_DEVICE_INFORMATION_OUTPUT_BUFFER includes an array of variable-length arrays, each of which returns an output argument representing the sub-system ID string, vendor ID string, and instance ID string, respectively.

IOCTL_ACPI_GET_DEVICE_INFORMATION can be used only at IRQL <= DISPATCH_LEVEL.

## See also

[ACPI_DEVICE_INFORMATION_OUTPUT_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/acpiioct/ns-acpiioct-_acpi_device_information_output_buffer)