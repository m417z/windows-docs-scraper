# IOCTL_HID_WRITE_REPORT IOCTL

## Description

The IOCTL_HID_WRITE_REPORT request sends a HID report to a HIDClass device.

For general information about HIDClass devices, see [HID Collections](https://learn.microsoft.com/windows-hardware/drivers/hid/hid-collections).

## Parameters

### Major code

### Input buffer

**Irp->UserBuffer**  points to a [HID_XFER_PACKET](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidclass/ns-hidclass-_hid_xfer_packet) structure the contains the parameters and report to be transmitted to the device. The following members are used:

### Input buffer length

The size of a [HID_XFER_PACKET](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidclass/ns-hidclass-_hid_xfer_packet) structure.

### Output buffer

None.

### Output buffer length

None.

### Input/output buffer

### Input/output buffer length

### Status block

 HID minidrivers that carry out the I/O to the device set the following fields of **Irp->IoStatus**:

* **Information** is set to the number of bytes transferred to the device.
* **Status** is set to STATUS_SUCCESS if the transfer completed without error. Otherwise, it is set to an appropriate NTSTATUS error code.

HID minidrivers that call other drivers with this IOCTL to carry out the I/O to their device, should ensure that the **Information** field of the status block is correct and not change the contents of the **Status** field.

## -ReportID

Specifies the report identifier, for this collection, of the report data to be written to the device.

## -reportBuffer

A pointer to a resident buffer containing the data to be sent to the device.

## -reportBufferLen

Specifies the length of the buffer provided at **reportBuffer**.

## See also

[HID_XFER_PACKET](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidclass/ns-hidclass-_hid_xfer_packet)

[HidD_GetFeature](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidsdi/nf-hidsdi-hidd_getfeature)

[HidD_GetInputReport](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidsdi/nf-hidsdi-hidd_getinputreport)

[HidD_SetFeature](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidsdi/nf-hidsdi-hidd_setfeature)

[HidD_SetOutputReport](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidsdi/nf-hidsdi-hidd_setoutputreport)

[IOCTL_HID_GET_FEATURE](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidclass/ni-hidclass-ioctl_hid_get_feature)

[IOCTL_HID_GET_INPUT_REPORT](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidclass/ni-hidclass-ioctl_hid_get_input_report)

[IOCTL_HID_READ_REPORT](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidport/ni-hidport-ioctl_hid_read_report)

[IOCTL_HID_SET_FEATURE](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidclass/ni-hidclass-ioctl_hid_set_feature)

[IOCTL_HID_SET_OUTPUT_REPORT](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidclass/ni-hidclass-ioctl_hid_set_output_report)