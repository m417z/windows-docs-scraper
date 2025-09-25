# IOCTL_GET_PHYSICAL_DESCRIPTOR IOCTL

## Description

The IOCTL_GET_PHYSICAL_DESCRIPTOR request obtains the physical descriptor of a [top-level collection](https://learn.microsoft.com/windows-hardware/drivers/hid/top-level-collections). For a minidriver, this descriptor is the descriptor of the HIDClass device.

For general information about HIDClass devices, see [HID Collections](https://learn.microsoft.com/windows-hardware/drivers/hid/hid-collections).

## Parameters

### Major code

### Input buffer

**Parameters.DeviceIoControl.OutputBufferLength** in the I/O stack location of the IRP indicates the size, in bytes, of the output buffer.

### Input buffer length

### Output buffer

**Irp->MdlAddress** must point to the buffer that will receive the physical descriptor.

The HID minidriver copies the physical descriptor into the user buffer at **Irp->UserBuffer**.

### Output buffer length

### Input/output buffer

### Input/output buffer length

### Status block

The HID class driver sets the **Status** member of **Irp->IoStatus** to STATUS_SUCCESS if the transfer completed without error. Otherwise, it is set to an appropriate NTSTATUS error code.

HID minidrivers that carry out the I/O to the device set the following fields of **Irp->IoStatus**:

* **Information** is set to the number of bytes transferred from the device.
* **Status** is set to STATUS_SUCCESS if the transfer completed without error. Otherwise, it is set to an appropriate NTSTATUS error code.

HID minidrivers that call other drivers with this IRP to carry out the I/O to their device should ensure that the **Information** field of the status block is correct and not change the contents of the **Status** field.

## See also

[HidD_GetPhysicalDescriptor](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidsdi/nf-hidsdi-hidd_getphysicaldescriptor)