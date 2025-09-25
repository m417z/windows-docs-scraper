# _HID_XFER_PACKET structure (hidclass.h)

## Description

The HID_XFER_PACKET structure contains information about a HID report that the HID class driver uses with I/O requests to get or set a report.

## Members

### `reportBuffer`

Pointer to a report buffer.

### `reportBufferLen`

Specifies the length of the report at **reportBuffer**.

### `reportId`

Specifies the report ID of the report contained at **reportBuffer**. This parameter is optional, and, if not specified, should be set to zero.

## Remarks

The HID class driver uses this structure to specify information about a HID report when it uses an I/O request to get or set a report.

## See also

[IOCTL_HID_GET_FEATURE](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidclass/ni-hidclass-ioctl_hid_get_feature)

[IOCTL_HID_GET_INPUT_REPORT](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidclass/ni-hidclass-ioctl_hid_get_input_report)

[IOCTL_HID_SET_FEATURE](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidclass/ni-hidclass-ioctl_hid_set_feature)

[IOCTL_HID_SET_OUTPUT_REPORT](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidclass/ni-hidclass-ioctl_hid_set_output_report)