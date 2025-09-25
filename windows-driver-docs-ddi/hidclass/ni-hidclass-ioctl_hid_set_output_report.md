# IOCTL_HID_SET_OUTPUT_REPORT IOCTL

## Description

The IOCTL_HID_SET_OUTPUT_REPORT request sends an output report to a [top-level collection](https://learn.microsoft.com/windows-hardware/drivers/hid/top-level-collections).

For general information about HIDClass devices, see [HID Collections](https://learn.microsoft.com/windows-hardware/drivers/hid/hid-collections).

## Parameters

### Major code

### Input buffer

The `Parameters.DeviceIoControl.InputBufferLength` member is set to the size, in bytes, of a requester-allocated input buffer that contains a HID class output report.

The size of the input buffer in bytes. The buffer must be large enough to hold the output report plus one additional byte that specifies a nonzero report ID. If report ID is not used, the ID value is zero.

The `Irp->AssociatedIrp.SystemBuffer` member points to the input buffer that contains an output report. If the collection includes report IDs, the requester must set the first byte of the buffer to a nonzero report ID. Otherwise, the requester must set the first byte to zero. The output report is located at `((PUCHAR)ReportBuffer + 1)`.

**Minidriver handling**

`Irp->UserBuffer` points to a [HID_XFER_PACKET](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidclass/ns-hidclass-_hid_xfer_packet) structure that the HID class driver uses to input the following members:

### Input buffer length

The size of the input buffer in bytes. The buffer must be large enough to hold the output report plus one additional byte that specifies a nonzero report ID. If report ID is not used, the ID value is zero.

**Minidriver handling**

The size of a [HID_XFER_PACKET](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidclass/ns-hidclass-_hid_xfer_packet) structure.

### Output buffer

None.

### Output buffer length

None.

### Input/output buffer

### Input/output buffer length

### Status block

The HID class driver sets the following fields of `Irp->IoStatus`:

- *Information* is set to zero.
- *Status* is set to STATUS_SUCCESS if the transfer completed without error. Otherwise, it is set to an appropriate NTSTATUS error code.

**Minidriver handling**

HID minidrivers that carry out the I/O to the device set the following fields of `Irp->IoStatus`:

- *Information* is set to the number of bytes transferred to the device.
- *Status* is set to STATUS_SUCCESS if the transfer completed without error. Otherwise, it is set to an appropriate NTSTATUS error code.

HID minidrivers that call other drivers with this IOCTL to carry out the I/O should ensure that the *Information* field of the status block is correct and not change the contents of the *Status* field.

## -ReportID

Specifies the report ID for a top-level collection.

## -reportBuffer

Pointer to a requester-allocated input buffer that contains an output report.

## -reportBufferLen

Specifies the size, in bytes, of the output buffer.

## See also

- [HidD_GetFeature](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidsdi/nf-hidsdi-hidd_getfeature)
- [HidD_GetInputReport](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidsdi/nf-hidsdi-hidd_getinputreport)
- [HidD_SetFeature](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidsdi/nf-hidsdi-hidd_setfeature)
- [HidD_SetOutputReport](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidsdi/nf-hidsdi-hidd_setoutputreport)
- [IOCTL_HID_GET_FEATURE](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidclass/ni-hidclass-ioctl_hid_get_feature)
- [IOCTL_HID_GET_INPUT_REPORT](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidclass/ni-hidclass-ioctl_hid_get_input_report)
- [IOCTL_HID_SET_FEATURE](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidclass/ni-hidclass-ioctl_hid_set_feature)