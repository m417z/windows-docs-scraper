# _FILTER_VOLUME_STANDARD_INFORMATION structure

## Description

The caller-allocated FILTER_VOLUME_STANDARD_INFORMATION structure contains information for a volume.

## Members

### `NextEntryOffset`

Read-only offset, in bytes, of the next FILTER_VOLUME_STANDARD_INFORMATION structure if multiple structures are present in the buffer. This member is zero if no other structures follow this one.

### `Flags`

A read-only bitmask of system-defined flags that describe attributes of the volume. The following are valid flag values.

| Flag | Meaning |
| --- | --- |
| FLTFL_VSI_DETACHED_VOLUME | The volume in not currently attached to a storage stack. |

### `FrameID`

Read-only member used to identify the filter manager frame that the volume is in.

### `FileSystemType`

Read-only member used to identify the type of file system being used on the volume. The possible values for this member are listed in [FLT_FILESYSTEM_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltuserstructures/ne-fltuserstructures-_flt_filesystem_type).

### `FilterVolumeNameLength`

Read-only length, in bytes, of the volume name.

### `FilterVolumeName`

Read-only name of the volume of **FilterVolumeNameLength** length. This Unicode string is not NULL-terminated.

## Remarks

Filter manager enumeration routines, such as [FltEnumerateVolumeInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltenumeratevolumeinformation), can fill a buffer with structures of type FILTER_VOLUME_STANDARD_INFORMATION where each structure represents a volume known to filter manager. This list of structures can contain multiple volumes with the same name. For more information, see [Understanding Volume Enumerations with Duplicate Volume Names](https://learn.microsoft.com/windows-hardware/drivers/ifs/understanding-volume-enumerations-with-duplicate-volume-names).

The FILTER_VOLUME_STANDARD_INFORMATION structure must be aligned on a LONGLONG (8-byte) boundary. If a buffer contains two or more of these structures, the **NextEntryOffset** value in each entry falls on an 8-byte boundary.

A FILTER_VOLUME_STANDARD_INFORMATION structure can be allocated from paged or nonpaged pool.

## See also

[FILTER_VOLUME_BASIC_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltuserstructures/ns-fltuserstructures-_filter_volume_basic_information)

[FilterVolumeFindClose](https://learn.microsoft.com/windows/win32/api/fltuser/nf-fltuser-filtervolumefindclose)

[FilterVolumeFindFirst](https://learn.microsoft.com/windows/win32/api/fltuser/nf-fltuser-filtervolumefindfirst)

[FilterVolumeFindNext](https://learn.microsoft.com/windows/win32/api/fltuser/nf-fltuser-filtervolumefindnext)

[FltEnumerateVolumeInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltenumeratevolumeinformation)

[FltEnumerateVolumes](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltenumeratevolumes)