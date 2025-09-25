# IOCTL_ACPI_ENUM_CHILDREN IOCTL

## Description

The IOCTL_ACPI_ENUM_CHILDREN device control request can be used to enumerate the path and name of devices or named child objects in the ACPI namespace of the device to which this request is sent. A driver should call [IoBuildDeviceIoControlRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iobuilddeviceiocontrolrequest) and pass the following input and output parameters to build this request.

## Parameters

### Major code

### Input buffer

Set the **IoBuildDeviceIoControlRequest** input parameters as follows:

* *IoControlCode* is set to IOCTL_ACPI_ENUM_CHILDREN.
* *DeviceObject* is set to a pointer to the physical device object (PDO) of the device.
* *InputBuffer* is set to a pointer to a variable-length [ACPI_ENUM_CHILDREN_INPUT_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/acpiioct/ns-acpiioct-_acpi_enum_children_input_buffer) structure.
* *InputBufferLength* is set to the size, in bytes, of the input buffer that is supplied by *InputBuffer*.
* *OutputBufferLength* supplies the size, in bytes, of the output buffer that is supplied by *OutputBuffer*.
* *InternalDeviceIoControl* is set to **FALSE**.
* *Event* is set to a pointer to a caller-allocated and initialized event object.

### Input buffer length

*InputBufferLength* is set to the size, in bytes, of the input buffer that is supplied by *InputBuffer*.

### Output buffer

Set the **IoBuildDeviceIoControlRequest** output parameters as follows:

* *OutputBuffer* supplies a pointer to a variable-length [ACPI_ENUM_CHILDREN_OUTPUT_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/acpiioct/ns-acpiioct-_acpi_enum_children_output_buffer) structure in which the ACPI driver returns the path and name of the enumerated child devices.
* *IoStatusBlock* is set to an [IO_STATUS_BLOCK](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_io_status_block) structure.

### Output buffer length

*OutputBufferLength* supplies the size, in bytes, of the output buffer that is supplied by *OutputBuffer*.

### Input/output buffer

### Input/output buffer length

### Status block

If the request succeeds, *IoStatusBlock*->**Status** is set to STATUS_SUCCESS; otherwise, the **Status** member is set to an error code. If the output buffer is not large enough to contain the buffer header, the **Status** member is set to STATUS_BUFFER_TOO_SMALL. If the output buffer is large enough to contain the output buffer header, but is not large enough to contain the paths and names of all the enumerated child objects, the **Status** member is set to STATUS_BUFFER_OVERFLOW and *OutputBuffer*->**NumberOfChildren** is set to the required length of the output buffer.

If the request succeeds, the *IoStatusBlock*->**Information** member is set to the number of bytes that is returned in the output buffer; otherwise, the **Information** member is set to zero.

## Remarks

IOCTL_ACPI_ENUM_CHILDREN returns a variable-length ACPI_ENUM_CHILDREN_OUTPUT_BUFFER structure that contains an array of variable-length [ACPI_ENUM_CHILD](https://learn.microsoft.com/windows-hardware/drivers/ddi/acpiioct/ns-acpiioct-_acpi_enum_child) structures, each of which returns the fully qualified path and name of an object in the ACPI namespace of the device to which the request was sent. The objects that this request enumerates depends on the setting of the **Flags** member of the supplied input structure ACPI_ENUM_CHILDREN_INPUT_BUFFER, as follows:

If the output buffer that the driver allocates is not large enough to return all requested child names, the ACPI driver does not return any child names and sets the **Status** member of the IO_STATUS_BLOCK for the request to STATUS_BUFFER_OVERFLOW. In this case, if the size, in bytes, of the output buffer is at least **sizeof**(ACPI_ENUM_CHILDREN_OUTPUT_BUFFER_SIGNATURE), the ACPI driver also sets *NumberOfChildren* to the size, in bytes, that is required to retrieve the requested paths and names.

A driver typically would use a sequence of two IOCTL_ACPI_ENUM_CHILDREN requests to enumerate the child objects of interest. The driver sends the first request to obtain the size of the output buffer that is required to contain the path and name of all the requested objects. The driver sends the second request to return the path and name of the objects in the output buffer.

For more information about how to enumerate child devices of a device, see [Enumerating Child Devices and Control Methods](https://learn.microsoft.com/windows-hardware/drivers/acpi/enumerating-child-devices-and-control-methods).

IOCTL_ACPI_ENUM_CHILDREN can be used only at IRQL< DISPATCH_LEVEL.

## See also

[ACPI_ENUM_CHILD](https://learn.microsoft.com/windows-hardware/drivers/ddi/acpiioct/ns-acpiioct-_acpi_enum_child)

[ACPI_ENUM_CHILDREN_INPUT_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/acpiioct/ns-acpiioct-_acpi_enum_children_input_buffer)

[ACPI_ENUM_CHILDREN_OUTPUT_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/acpiioct/ns-acpiioct-_acpi_enum_children_output_buffer)