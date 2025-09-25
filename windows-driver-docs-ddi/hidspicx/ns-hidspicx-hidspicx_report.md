## Description

The **HIDSPICX_REPORT** structure is used to represent input and output reports.

## Members

### `ReportType`

The content type of the report.

### `ReportContentLength`

The length of the *ReportContent* field.

### `ReportId`

A unique report identifier.

### `ReportContent`

The raw HID report or command parameters.

## Remarks

This structure is used rather than the full report structure including the header as the client is expected to marshall the data structures to be sent on the wire.

## See also

[**HIDSPICX_DEVICE_CONFIG_INIT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidspicx/nf-hidspicx-hidspicx_device_config_init)

[**HIDSPICX_DEVICE_CONFIG**](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidspicx/ns-hidspicx-hidspicx_device_config)