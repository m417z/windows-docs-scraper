# _FILTER_AGGREGATE_BASIC_INFORMATION structure

## Description

The FILTER_AGGREGATE_BASIC_INFORMATION structure contains basic information for a minifilter or legacy filter driver.

## Members

### `NextEntryOffset`

Byte offset of the next FILTER_AGGREGATE_BASIC_INFORMATION entry, if multiple entries are present in a buffer. This member is zero if no other entries follow this one.

### `Flags`

Indicates whether the filter driver is a legacy filter or a minifilter. This member must be one of the following values.

| Flag | Meaning |
| --- | --- |
| FLTFL_AGGREGATE_INFO_IS_MINIFILTER | The filter is a minifilter - use the **MiniFilter** portion of the union. |
| FLTFL_AGGREGATE_INFO_IS_LEGACYFILTER | The filter is a legacy filter - use the **LegacyFilter** portion of the union. |

### `Type`

### `Type.MiniFilter`

### `Type.MiniFilter.FrameID`

Zero-based index of the current frame.

### `Type.MiniFilter.NumberOfInstances`

Number of instances that currently exist for the minifilter.

### `Type.MiniFilter.FilterNameLength`

Length, in bytes, of the filter name.

### `Type.MiniFilter.FilterNameBufferOffset`

Byte offset of the first character of the filter name string.

### `Type.MiniFilter.FilterAltitudeLength`

Length, in bytes, of the minifilter altitude string.

### `Type.MiniFilter.FilterAltitudeBufferOffset`

Byte offset of the first character of the minifilter altitude string.

### `Type.LegacyFilter`

### `Type.LegacyFilter.FilterNameLength`

Length, in bytes, of the filter name.

### `Type.LegacyFilter.FilterNameBufferOffset`

Byte offset of the first character of the filter name string.

## Remarks

The FILTER_AGGREGATE_BASIC_INFORMATION structure is passed as a parameter to routines such as [FilterFindFirst](https://learn.microsoft.com/windows/win32/api/fltuser/nf-fltuser-filterfindfirst), [FilterFindNext](https://learn.microsoft.com/windows/win32/api/fltuser/nf-fltuser-filterfindnext), [FilterGetInformation](https://learn.microsoft.com/windows/win32/api/fltuser/nf-fltuser-filtergetinformation), [FltEnumerateFilterInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltenumeratefilterinformation), and [FltGetFilterInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltgetfilterinformation).

This structure must be aligned on a LONGLONG (8-byte) boundary. If a buffer contains two or more of these structures, the **NextEntryOffset** value in each entry, except the last, falls on an 8-byte boundary.

## See also

[FILTER_AGGREGATE_STANDARD_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltuserstructures/ns-fltuserstructures-_filter_aggregate_standard_information)

[FILTER_FULL_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltuserstructures/ns-fltuserstructures-_filter_full_information)

[FilterFindClose](https://learn.microsoft.com/windows/win32/api/fltuser/nf-fltuser-filterfindclose)

[FilterFindFirst](https://learn.microsoft.com/windows/win32/api/fltuser/nf-fltuser-filterfindfirst)

[FilterFindNext](https://learn.microsoft.com/windows/win32/api/fltuser/nf-fltuser-filterfindnext)

[FilterGetInformation](https://learn.microsoft.com/windows/win32/api/fltuser/nf-fltuser-filtergetinformation)

[FltEnumerateFilterInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltenumeratefilterinformation)

[FltGetFilterInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltgetfilterinformation)