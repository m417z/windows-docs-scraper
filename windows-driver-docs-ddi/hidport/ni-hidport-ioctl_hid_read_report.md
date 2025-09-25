# IOCTL_HID_READ_REPORT IOCTL

## Description

The IOCTL_HID_READ_REPORT request transfers an input report from a HIDClass device into the HID class driver's buffer.

For general information about HIDClass devices, see [HID Collections](https://learn.microsoft.com/windows-hardware/drivers/hid/hid-collections).

## Parameters

### Major code

### Input buffer

**Parameters.DeviceIoControl.OutputBufferLength** contains the size of the buffer provided at **Irp->UserBuffer**.

### Input buffer length

The size of **OutputBufferLength**

### Output buffer

 HID minidriver fills the system-resident buffer pointed to by **Irp->UserBuffer** with the report data retrieved from the device.

### Output buffer length

The size of the **UserBuffer**.

### Input/output buffer

### Input/output buffer length

### Status block

HID minidrivers that carry out the I/O to the device set the following fields of **Irp->IoStatus**:

* **Information** is set to the number of bytes transferred from the device.
* **Status** is set to STATUS_SUCCESS if the transfer completed without error. Otherwise, it is set to an appropriate NTSTATUS error code.

HID minidrivers that call other drivers with this IRP to carry out the I/O to their device should ensure that the **Information** field of the status block is correct and not change the contents of the **Status** field.

## Remarks

IOCTL_HID_READ_REPORT is typically used for continuously completing input reports that are sent by the device. This IOCTL is sent down by the HID class driver (HIDCLASS) in ping-pong fashion. In other words, as soon as a request is fulfilled (completed), another one can be sent down to the device, allowing for continuous reporting of data. This is an “asynchronous” mechanism, so for example, the device can use it to send data up to the host, regarding changes in state as those changes occur.

## See also

[HidD_GetFeature](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidsdi/nf-hidsdi-hidd_getfeature)

[HidD_GetInputReport](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidsdi/nf-hidsdi-hidd_getinputreport)

[HidD_SetFeature](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidsdi/nf-hidsdi-hidd_setfeature)

[HidD_SetOutputReport](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidsdi/nf-hidsdi-hidd_setoutputreport)

[IOCTL_HID_GET_FEATURE](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidclass/ni-hidclass-ioctl_hid_get_feature)

[IOCTL_HID_GET_INPUT_REPORT](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidclass/ni-hidclass-ioctl_hid_get_input_report)

[IOCTL_HID_SET_FEATURE](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidclass/ni-hidclass-ioctl_hid_set_feature)

[IOCTL_HID_SET_OUTPUT_REPORT](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidclass/ni-hidclass-ioctl_hid_set_output_report)

[IOCTL_HID_WRITE_REPORT](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidport/ni-hidport-ioctl_hid_write_report)