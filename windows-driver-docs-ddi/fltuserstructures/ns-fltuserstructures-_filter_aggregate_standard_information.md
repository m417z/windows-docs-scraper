# _FILTER_AGGREGATE_STANDARD_INFORMATION structure

## Description

The FILTER_AGGREGATE_STANDARD_INFORMATION structure contains information about a minifilter or legacy filter driver.

## Members

### `NextEntryOffset`

Byte offset of the next FILTER_AGGREGATE_STANDARD_INFORMATION entry, if multiple entries are present in a buffer. This member is zero if no other entries follow this one.

### `Flags`

Indicates whether the filter driver is a legacy filter or a minifilter. This member must be one of the following values.

| Flag | Meaning |
| --- | --- |
| FLTFL_ASI_IS_MINIFILTER | The filter is a minifilter - use the **MiniFilter** portion of the union. |
| FLTFL_ASI_IS_LEGACYFILTER | The filter is a legacy filter - use the **LegacyFilter** portion of the union. |

### `Type`

### `Type.MiniFilter`

Nested structure variable with the following members:

### `Type.MiniFilter.Flags`

There are currently no flags defined for this member.

### `Type.MiniFilter.FrameID`

Zero-based index used to identify the filter manager frame that the minifilter is in.

### `Type.MiniFilter.NumberOfInstances`

Number of instances that currently exist for the minifilter.

### `Type.MiniFilter.FilterNameLength`

Length, in bytes, of the minifilter name string.

### `Type.MiniFilter.FilterNameBufferOffset`

Byte offset (relative to the beginning of the structure) of the first character of the Unicode minifilter name string. The string is not NULL-terminated.

### `Type.MiniFilter.FilterAltitudeLength`

Length, in bytes, of the minifilter altitude string.

### `Type.MiniFilter.FilterAltitudeBufferOffset`

Byte offset (relative to the beginning of the structure) of the first character of the Unicode minifilter altitude string. The string is not NULL-terminated.

### `Type.LegacyFilter`

Nested structure variable with the following members:

### `Type.LegacyFilter.Flags`

There are currently no flags defined for this member.

### `Type.LegacyFilter.FilterNameLength`

Length, in bytes, of the legacy filter name string.

### `Type.LegacyFilter.FilterNameBufferOffset`

Byte offset (relative to the beginning of the structure) of the first character of the Unicode legacy filter name string. The string is not NULL-terminated.

### `Type.LegacyFilter.FilterAltitudeLength`

Length, in bytes, of the legacy filter altitude string.

### `Type.LegacyFilter.FilterAltitudeBufferOffset`

Byte offset (relative to the beginning of the structure) of the first character of the Unicode legacy filter altitude string. The string is not NULL-terminated.

Starting with Windows Vista, altitudes are assigned to legacy filter drivers based on the driver's load order group. This ensures that minifilter drivers will layer properly above and below legacy filter drivers even if one or more of the filter drivers are loaded out-of-order.

## Remarks

The FILTER_AGGREGATE_STANDARD_INFORMATION structure can be allocated from paged or nonpaged pool. This structure is passed as a parameter to routines such as:

* [FilterFindFirst](https://learn.microsoft.com/windows/win32/api/fltuser/nf-fltuser-filterfindfirst)
* [FilterFindNext](https://learn.microsoft.com/windows/win32/api/fltuser/nf-fltuser-filterfindnext)
* [FilterGetInformation](https://learn.microsoft.com/windows/win32/api/fltuser/nf-fltuser-filtergetinformation)
* [FltEnumerateFilterInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltenumeratefilterinformation)
* [FltGetFilterInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltgetfilterinformation)

The FILTER_AGGREGATE_STANDARD_INFORMATION structure must be aligned on a LONGLONG (8-byte) boundary. If a buffer contains two or more of these structures, the **NextEntryOffset** value in each entry falls on an 8-byte boundary.

## See also

[FILTER_AGGREGATE_BASIC_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltuserstructures/ns-fltuserstructures-_filter_aggregate_basic_information)

[FILTER_FULL_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltuserstructures/ns-fltuserstructures-_filter_full_information)

[FilterFindFirst](https://learn.microsoft.com/windows/win32/api/fltuser/nf-fltuser-filterfindfirst)

[FilterFindNext](https://learn.microsoft.com/windows/win32/api/fltuser/nf-fltuser-filterfindnext)

[FilterGetInformation](https://learn.microsoft.com/windows/win32/api/fltuser/nf-fltuser-filtergetinformation)

[FltEnumerateFilterInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltenumeratefilterinformation)

[FltGetFilterInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltgetfilterinformation)