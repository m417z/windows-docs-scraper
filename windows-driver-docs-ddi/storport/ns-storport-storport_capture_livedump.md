## Description

The **STORPORT_CAPTURE_LIVEDUMP** structure contains the data needed to generate a live dump.

## Members

### `Version`

Size, in bytes, of this structure. The structure size serves as the version.

### `Size`

Size, in bytes, of this structure plus all of its variable-sized fields.

### `LiveDumpType`

A [**STORPORT_CAPTURE_LIVEDUMP_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ne-storport-storport_capture_livedump_type) enum value that identifies the type of live dump to capture.

### `IssueType`

A [**STORPORT_LIVEDUMP_ISSUE_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ne-storport-storport_livedump_issue_type) enum value that identifies the issue that triggers the live dump capture.

### `ComponentName`

Pointer to a string name that identifies the component that is creating the live dump.

### `DataType`

A [**STORPORT_LIVEDUMP_DATA_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ne-storport-storport_livedump_data_type) enum value that specifies the data type of the payload to be included in the live dump.

### `Data`

Pointer to the payload to be included in the live dump.

## Remarks

A miniport calls [**StorPortCaptureLiveDump**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportcapturelivedump) with the data in this structure to capture a live dump file.

## See also

[**STORPORT_CAPTURE_LIVEDUMP_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ne-storport-storport_capture_livedump_type)

[**STORPORT_LIVEDUMP_DATA_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ne-storport-storport_livedump_data_type)

[**STORPORT_LIVEDUMP_ISSUE_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ne-storport-storport_livedump_issue_type)

[**StorPortCaptureLiveDump**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportcapturelivedump)