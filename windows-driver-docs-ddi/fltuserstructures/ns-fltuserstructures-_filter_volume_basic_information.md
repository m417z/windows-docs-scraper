# _FILTER_VOLUME_BASIC_INFORMATION structure

## Description

The caller-allocated FILTER_VOLUME_BASIC_INFORMATION structure contains basic information for a volume.

## Members

### `FilterVolumeNameLength`

Read-only length, in bytes, of the volume name.

### `FilterVolumeName`

Read-only name of the volume of **FilterVolumeNameLength** length. This Unicode string is not NULL-terminated.

## Remarks

Filter manager enumeration routines, such as [FltEnumerateVolumeInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltenumeratevolumeinformation), can fill a buffer with structures of type FILTER_VOLUME_BASIC_INFORMATION where each structure represents a volume known to filter manager. This list of structures can contain multiple volumes with the same name. For more information, see [Understanding Volume Enumerations with Duplicate Volume Names](https://learn.microsoft.com/windows-hardware/drivers/ifs/understanding-volume-enumerations-with-duplicate-volume-names).

The FILTER_VOLUME_BASIC_INFORMATION structure must be aligned on a LONGLONG (8-byte) boundary. If a buffer contains two or more of these structures, the **NextEntryOffset** value in each structure falls on an 8-byte boundary.

A FILTER_VOLUME_BASIC_INFORMATION structure can be allocated from paged or nonpaged pool.

## See also

[FILTER_VOLUME_STANDARD_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltuserstructures/ns-fltuserstructures-_filter_volume_standard_information)

[FilterVolumeFindClose](https://learn.microsoft.com/windows/win32/api/fltuser/nf-fltuser-filtervolumefindclose)

[FilterVolumeFindFirst](https://learn.microsoft.com/windows/win32/api/fltuser/nf-fltuser-filtervolumefindfirst)

[FilterVolumeFindNext](https://learn.microsoft.com/windows/win32/api/fltuser/nf-fltuser-filtervolumefindnext)

[FltEnumerateVolumeInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltenumeratevolumeinformation)