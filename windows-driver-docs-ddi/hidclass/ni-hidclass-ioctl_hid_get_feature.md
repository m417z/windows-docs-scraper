# IOCTL_HID_GET_FEATURE IOCTL

## Description

The IOCTL_HID_GET_FEATURE request returns a feature report associated with a [top-level collection](https://learn.microsoft.com/windows-hardware/drivers/hid/top-level-collections).

For general information about HIDClass devices, see [HID Collections](https://learn.microsoft.com/windows-hardware/drivers/hid/hid-collections).

## Parameters

### Major code

### Input buffer

The `Parameters.DeviceIoControl.OutputBufferLength` member specifies the size, in bytes, of a requester-allocated output buffer. The HID class driver uses this buffer to return a feature report.

If the collection includes report IDs, the requester must set the first byte of the output buffer to a nonzero report ID. Otherwise, the requester must set the first byte of the output buffer to zero.

**Minidriver handling**

`Irp->UserBuffer` points to a [HID_XFER_PACKET](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidclass/ns-hidclass-_hid_xfer_packet) structure that the HID class driver uses to input the following members:

### Input buffer length

The size of the buffer in bytes. The buffer must be large enough to hold the feature report plus one additional byte that specifies a nonzero report ID. If report ID is not used, the ID value is zero.

**Minidriver handling**

The size of the [HID_XFER_PACKET](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidclass/ns-hidclass-_hid_xfer_packet) structure.

### Output buffer

The `Irp->MdlAddress` member points to the requester-allocated output buffer that the HID class driver uses to return the feature report. The first byte of the buffer, which the requester uses to input a report ID or zero, is unchanged. The feature report, excluding its report ID, if report IDs are used, is returned at `((PUCHAR)Irp->MdlAddress + 1)`.

**Minidriver handling**

`((PHID_XFER_PACKET)(Irp->UserBuffer))->reportBuffer` points to the requester-allocated output buffer that the HID minidriver uses to return a feature report.

### Output buffer length

The length of the buffer that contains the report.

**Minidriver handling**

The size of the [HID_XFER_PACKET](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidclass/ns-hidclass-_hid_xfer_packet) structure.

### Input/output buffer

### Input/output buffer length

### Status block

The HID class driver sets the following fields of `Irp->IoStatus`:

- *Information* is set to the number of bytes transferred from the device.
- *Status* is set to STATUS_SUCCESS if the transfer completed without error. Otherwise, it is set to an appropriate NTSTATUS error code.

**Minidriver handling**

HID minidrivers that carry out the I/O to the device set the following fields of `Irp->IoStatus`:

- *Information* is set to the number of bytes transferred from the device.
- *Status* is set to STATUS_SUCCESS if the transfer completed without error. Otherwise, it is set to an appropriate NTSTATUS error code.

HID minidrivers that call other drivers with this IOCTL to carry out the I/O to their device, should ensure that the *Information* field of the status block is correct and not change the contents of the *Status* field.

## -ReportID

Specifies a report ID associated with a top-level collection.

## -reportBuffer

Points to a requester-allocated output buffer that a HID minidriver uses to return a feature report.

## -reportBufferLen

Specifies the size, in bytes, of the output buffer.

## See also

- [HidD_GetFeature](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidsdi/nf-hidsdi-hidd_getfeature)
- [HidD_GetInputReport](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidsdi/nf-hidsdi-hidd_getinputreport)
- [HidD_SetFeature](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidsdi/nf-hidsdi-hidd_setfeature)
- [HidD_SetOutputReport](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidsdi/nf-hidsdi-hidd_setoutputreport)
- [IOCTL_HID_GET_INPUT_REPORT](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidclass/ni-hidclass-ioctl_hid_get_input_report)
- [IOCTL_HID_SET_FEATURE](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidclass/ni-hidclass-ioctl_hid_set_feature)
- [IOCTL_HID_SET_OUTPUT_REPORT](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidclass/ni-hidclass-ioctl_hid_set_output_report)