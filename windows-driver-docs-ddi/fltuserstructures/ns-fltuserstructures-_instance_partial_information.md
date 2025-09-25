# _INSTANCE_PARTIAL_INFORMATION structure

## Description

The INSTANCE_PARTIAL_INFORMATION structure contains partial information for a minifilter instance.

## Members

### `NextEntryOffset`

Byte offset of the next INSTANCE_PARTIAL_INFORMATION entry, if multiple entries are present in a buffer. This member is zero if no other entries follow this one.

### `InstanceNameLength`

Length, in bytes, of the instance name.

### `InstanceNameBufferOffset`

Byte offset of the first character of the instance name string. This character is followed in memory by the remainder of the string.

### `AltitudeLength`

Length, in bytes, of the altitude string for the instance.

### `AltitudeBufferOffset`

Byte offset of the first character of the altitude string. This character is followed in memory by the remainder of the string.

## Remarks

This structure must be aligned on a LONGLONG (8-byte) boundary. If a buffer contains two or more of these structures, the **NextEntryOffset** value in each entry, except the last, falls on an 8-byte boundary.

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

[INSTANCE_FULL_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltuserstructures/ns-fltuserstructures-_instance_full_information)