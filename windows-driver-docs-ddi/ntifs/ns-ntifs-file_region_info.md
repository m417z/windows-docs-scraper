## Description

The **FILE_REGION_INFO** structure contains a computed region of a file based on a desired usage. This structure is used to store region information for the [**FSCTL_QUERY_FILE_REGIONS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ni-ntifs-fsctl_query_file_regions) reply message, with the [**FILE_REGION_OUTPUT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-file_region_output) structure containing one or more **FILE_REGION_INFO** structures.

## Members

### `FileOffset`

A 64-bit signed integer that contains the file offset, in bytes, of the region.

### `Length`

A 64-bit signed integer that contains the size, in bytes, of the region.

### `Usage`

A 32-bit unsigned integer that indicates the usage for the given region of the file. **Usage** can be one of the following values.

| Value | Meaning |
| ----- | ------- |
| 0x00000000 | The given range is invalid. It does not match the criteria of the requested [**DesiredUsage**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-file_region_input). |
| **FILE_USAGE_VALID_CACHED_DATA** (0x00000001) | Defines those regions of the file that exists before VDL as it exists in the cache manager. |
| **FILE_USAGE_VALID_NONCACHED_DATA** (0x00000002) | Defines those regions of the files that exist before VDL on the storage device. |

### `Reserved`

Reserved; this field should be set to zero and ignored.

## Remarks

## See also

[**FILE_REGION_INPUT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-file_region_input)

[**FILE_REGION_OUTPUT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-file_region_output)

[**FSCTL_QUERY_FILE_REGIONS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ni-ntifs-fsctl_query_file_regions)