## Description

**FILE_REGION_OUTPUT** is the output structure for [**FSCTL_QUERY_FILE_REGIONS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ni-ntifs-fsctl_query_file_regions).

## Members

### `Flags`

A 32-bit unsigned integer that indicates the flags for this operation. No flags are currently defined so this field should be set to zero and be ignored.

### `TotalRegionEntryCount`

A 32-bit unsigned integer that indicates the total number of regions that could be returned.

### `RegionEntryCount`

A 32-bit unsigned integer that indicates the number of regions that were actually returned and which are contained in this structure.

### `Reserved`

Reserved; this field should be set to zero and ignored.

### `Region[1]`

One or more [**FILE_REGION_INFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-file_region_info) structures that contain information on the desired ranges based on the desired usage indicated by [**DesiredUsage**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-file_region_input).

## Remarks

## See also

[**FILE_REGION_INFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-file_region_info)

[**FILE_REGION_INPUT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-file_region_input)

[**FSCTL_QUERY_FILE_REGIONS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ni-ntifs-fsctl_query_file_regions)