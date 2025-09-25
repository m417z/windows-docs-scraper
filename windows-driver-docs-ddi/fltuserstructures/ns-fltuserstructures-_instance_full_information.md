# _INSTANCE_FULL_INFORMATION structure

## Description

The INSTANCE_FULL_INFORMATION structure contains full information for a minifilter instance.

## Members

### `NextEntryOffset`

A byte offset of the next INSTANCE_FULL_INFORMATION entry. If multiple entries are present in a buffer, the last entry contains a zero.

### `InstanceNameLength`

The length, in bytes, of the instance name.

### `InstanceNameBufferOffset`

A byte offset of the first character of the instance name string. This character is followed in memory by the remainder of the string.

### `AltitudeLength`

The length, in bytes, of the altitude string.

### `AltitudeBufferOffset`

A byte offset of the first character of the altitude string. This character is followed in memory by the remainder of the string.

### `VolumeNameLength`

The length, in bytes, of the volume name.

### `VolumeNameBufferOffset`

A byte offset of the first character of the volume name string. This character is followed in memory by the remainder of the string (for example, "\Device\HarddiskVolume1").

### `FilterNameLength`

The length, in bytes, of the minifilter name.

### `FilterNameBufferOffset`

A byte offset of the first character of the minifilter name string. This character is followed in memory by the remainder of the string.

## Remarks

This structure must be aligned on a LONGLONG (8-byte) boundary. If a buffer contains two or more of these structures, the **NextEntryOffset** value in each entry, except the last, falls on an 8-byte boundary.

The content of all character string buffers referenced by this structure are Unicode.

## See also

[FilterAttachAtAltitude](https://learn.microsoft.com/windows/win32/api/fltuser/nf-fltuser-filterattachataltitude)

[FilterInstanceFindClose](https://learn.microsoft.com/windows/win32/api/fltuser/nf-fltuser-filterinstancefindclose)

[FilterInstanceFindFirst](https://learn.microsoft.com/windows/win32/api/fltuser/nf-fltuser-filterinstancefindfirst)

[FilterInstanceFindNext](https://learn.microsoft.com/windows/win32/api/fltuser/nf-fltuser-filterinstancefindnext)

[FilterInstanceGetInformation](https://learn.microsoft.com/windows/win32/api/fltuser/nf-fltuser-filterinstancegetinformation)

[FilterVolumeInstanceFindClose](https://learn.microsoft.com/windows/win32/api/fltuser/nf-fltuser-filtervolumeinstancefindclose)

[FilterVolumeInstanceFindFirst](https://learn.microsoft.com/windows/win32/api/fltuser/nf-fltuser-filtervolumeinstancefindfirst)

[FilterVolumeInstanceFindNext](https://learn.microsoft.com/windows/win32/api/fltuser/nf-fltuser-filtervolumeinstancefindnext)

[INSTANCE_AGGREGATE_STANDARD_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltuserstructures/ns-fltuserstructures-_instance_aggregate_standard_information)

[INSTANCE_BASIC_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltuserstructures/ns-fltuserstructures-_instance_basic_information)

[INSTANCE_PARTIAL_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltuserstructures/ns-fltuserstructures-_instance_partial_information)