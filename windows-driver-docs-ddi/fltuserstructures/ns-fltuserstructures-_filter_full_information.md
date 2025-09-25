# _FILTER_FULL_INFORMATION structure

## Description

The FILTER_FULL_INFORMATION structure contains full information for a minifilter driver.

## Members

### `NextEntryOffset`

Byte offset of the next FILTER_FULL_INFORMATION entry, if multiple entries are present in a buffer. This member is zero if no other entries follow this one.

### `FrameID`

Zero-based index of the current frame.

### `NumberOfInstances`

Number of instances that currently exist for this minifilter.

### `FilterNameLength`

Length, in bytes, of the minifilter name.

### `FilterNameBuffer`

Specifies the first character of the filter name string. This character is followed in memory by the remainder of the string. The length of the string is specified by the **FilterNameLength** member. The string is Unicode and is not NULL-terminated.

## Remarks

The FILTER_FULL_INFORMATION structure is passed as a parameter to routines such as [FilterFindFirst](https://learn.microsoft.com/windows/win32/api/fltuser/nf-fltuser-filterfindfirst), [FilterFindNext](https://learn.microsoft.com/windows/win32/api/fltuser/nf-fltuser-filterfindnext), [FilterGetInformation](https://learn.microsoft.com/windows/win32/api/fltuser/nf-fltuser-filtergetinformation), [FltEnumerateFilterInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltenumeratefilterinformation), and [FltGetFilterInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltgetfilterinformation).

This structure must be aligned on a LONGLONG (8-byte) boundary. If a buffer contains two or more of these structures, the **NextEntryOffset** value in each entry, except the last, falls on an 8-byte boundary.

## See also

[FILTER_AGGREGATE_BASIC_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltuserstructures/ns-fltuserstructures-_filter_aggregate_basic_information)

[FILTER_AGGREGATE_STANDARD_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltuserstructures/ns-fltuserstructures-_filter_aggregate_standard_information)

[FilterFindClose](https://learn.microsoft.com/windows/win32/api/fltuser/nf-fltuser-filterfindclose)

[FilterFindFirst](https://learn.microsoft.com/windows/win32/api/fltuser/nf-fltuser-filterfindfirst)

[FilterFindNext](https://learn.microsoft.com/windows/win32/api/fltuser/nf-fltuser-filterfindnext)

[FilterGetInformation](https://learn.microsoft.com/windows/win32/api/fltuser/nf-fltuser-filtergetinformation)

[FltEnumerateFilterInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltenumeratefilterinformation)

[FltGetFilterInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltgetfilterinformation)