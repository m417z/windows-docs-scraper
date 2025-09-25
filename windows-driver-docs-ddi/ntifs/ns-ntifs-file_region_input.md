## Description

**FILE_REGION_INPUT** is the optional input structure for [**FSCTL_QUERY_FILE_REGIONS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ni-ntifs-fsctl_query_file_regions).

## Members

### `FileOffset`

A 64-bit signed integer that contains the file offset, in bytes, of the start of a range of bytes in a file.

### `Length`

A 64-bit signed integer that contains the size, in bytes, of the range.

### `DesiredUsage`

A 32-bit unsigned integer that indicates usage parameters for this operation. **DesiredUsage** can be one of the following values.

| Value | Meaning |
| ----- | ------- |
| **FILE_REGION_USAGE_VALID_CACHED_DATA** (0x00000001) | Requests that information about the valid data length (VDL) for the specified file and file range in the cache be returned. |
| **FILE_REGION_USAGE_VALID_NONCACHED_DATA** (0x00000002) | Requests that information about the VDL for the specified file and file range on disk be returned. |
| All other values | If a **FILE_REGION_INPUT** object is specified in **FSCTL_QUERY_FILE_REGION**, then any other value will return STATUS_INVALID_PARAMETER. |

## Remarks

See [**FSCTL_QUERY_FILE_REGIONS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ni-ntifs-fsctl_query_file_regions) for details.

## See also

[**FILE_REGION_OUTPUT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-file_region_output)

[**FSCTL_QUERY_FILE_REGIONS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ni-ntifs-fsctl_query_file_regions)