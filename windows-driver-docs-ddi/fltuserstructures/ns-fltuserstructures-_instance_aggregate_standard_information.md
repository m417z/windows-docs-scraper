# INSTANCE_AGGREGATE_STANDARD_INFORMATION structure

## Description

The caller-allocated **INSTANCE_AGGREGATE_STANDARD_INFORMATION** structure contains aggregate standard information about either a minifilter driver instance or a legacy filter driver.

## Members

### `NextEntryOffset`

Byte offset of the next **INSTANCE_AGGREGATE_STANDARD_INFORMATION** structure if multiple structures are present in a buffer. This member is zero if no other structures follow this one.

### `Flags`

Indicates whether the filter driver is a legacy filter driver or a minifilter driver. This member must contain one of the following flags.

| Flag | Meaning |
| ---- | ------- |
| FLTFL_IASI_IS_MINIFILTER | The filter driver is a minifilter driver; use the **MiniFilter** portion of the union. |
| FLTFL_IASI_IS_LEGACYFILTER | The filter driver is a legacy filter driver; use the **LegacyFilter** portion of the union. |

### `Type`

Nested structure variable with the following members.

### `Type.MiniFilter`

### `Type.MiniFilter.Flags`

A bitmask of flags that describe attributes of the minifilter instance. The following are valid flag values.

| Flag | Meaning |
| ---- | ------- |
| FLTFL_IASIM_DETACHED_VOLUME | The volume is not currently attached to a storage stack. |

### `Type.MiniFilter.FrameID`

Zero-based index used to identify the filter manager frame that the minifilter instance is in.

### `Type.MiniFilter.VolumeFileSystemType`

Identifies the type of file system the minifilter instance is attached to. The possible values for this member are listed in [FLT_FILESYSTEM_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltuserstructures/ne-fltuserstructures-_flt_filesystem_type).

### `Type.MiniFilter.InstanceNameLength`

Length, in bytes, of the minifilter instance name.

### `Type.MiniFilter.InstanceNameBufferOffset`

Byte offset (relative to the beginning of the structure) of the first character of the Unicode minifilter instance name string. This string is not NULL-terminated.

### `Type.MiniFilter.AltitudeLength`

Length, in bytes, of the minifilter instance altitude string.

### `Type.MiniFilter.AltitudeBufferOffset`

Byte offset (relative to the beginning of the structure) of the first character of the Unicode minifilter instance altitude string. This string is not NULL-terminated.

### `Type.MiniFilter.VolumeNameLength`

Length, in bytes, of the volume name of the volume that the minifilter instance is attached to.

### `Type.MiniFilter.VolumeNameBufferOffset`

Byte offset (relative to the beginning of the structure) of the first character of the Unicode volume name string for the volume that the minifilter instance is attached to. This string is not NULL-terminated.

### `Type.MiniFilter.FilterNameLength`

Length, in bytes, of the minifilter name of the minifilter from which the minifilter instance was derived.

### `Type.MiniFilter.FilterNameBufferOffset`

Byte offset (relative to the beginning of the structure) of the first character of the Unicode minifilter name string for the minifilter from which the minifilter instance was derived. This string is not NULL-terminated.

### `Type.MiniFilter.SupportedFeatures`

The supported feature flags for the filter, as specified by a minifilter's **SupportedFeatures** Registry value. The supported features are a bitwise OR combination of the following flags.

| Value | Meaning |
| ----- | ------- |
| **SUPPORTED_FS_FEATURES_OFFLOAD_READ** (0x01) | The volume supports offloaded read operations. |
| **SUPPORTED_FS_FEATURES_OFFLOAD_WRITE** (0x02) | The volume supports offloaded write operations. |
| **SUPPORTED_FS_FEATURES_QUERY_OPEN** (0x04) | The volume supports query open operations. |
| **SUPPORTED_FS_FEATURES_BYPASS_IO** (0x08) | The volume supports [BypassIO](https://learn.microsoft.com/windows-hardware/drivers/ifs/bypassio). This flag is available starting in Windows 11. |

### `Type.LegacyFilter`

Nested structure variable with the following members.

### `Type.LegacyFilter.Flags`

A bitmask of flags that describe attributes of the legacy filter. The following are valid flag values.

| Flag | Meaning |
| ---- | ------- |
| FLTFL_IASIL_DETACHED_VOLUME | The volume is not currently attached to a storage stack. |

### `Type.LegacyFilter.AltitudeLength`

Length, in bytes, of the legacy filter altitude string.

### `Type.LegacyFilter.AltitudeBufferOffset`

Byte offset (relative to the beginning of the structure) of the first character of the Unicode legacy filter altitude string. This string is not NULL-terminated.

Starting with Windows Vista, altitudes are assigned to legacy filter drivers based on the driver's load order group. This ensures that minifilter drivers will layer properly above and below legacy filter drivers even if one or more of the filter drivers are loaded out-of-order.

### `Type.LegacyFilter.VolumeNameLength`

Length, in bytes, of the volume name of the volume that the legacy filter is attached to.

### `Type.LegacyFilter.VolumeNameBufferOffset`

Byte offset (relative to the beginning of the structure) of the first character of the Unicode volume name string for the volume that the legacy filter is attached to. This string is not NULL-terminated.

### `Type.LegacyFilter.FilterNameLength`

Length, in bytes, of the legacy filter name.

### `Type.LegacyFilter.FilterNameBufferOffset`

Byte offset (relative to the beginning of the structure) of the first character of the Unicode legacy filter name string. This string is not NULL-terminated.

### `Type.LegacyFilter.SupportedFeatures`

The supported feature flags for the legacy filter.

The supported features are a bitwise OR combination of the following flags.

| Value | Meaning |
| ----- | ------- |
| SUPPORTED_FS_FEATURES_OFFLOAD_READ (0x01) | The volume supports offloaded read operations. |
| SUPPORTED_FS_FEATURES_OFFLOAD_WRITE (0x02) | The volume supports offloaded write operations. |

## Remarks

A structure of type **INSTANCE_AGGREGATE_STANDARD_INFORMATION** can be allocated from paged or nonpaged pool. This structure is passed as a parameter to routines such as the following:

- [FilterInstanceFindFirst](https://learn.microsoft.com/windows/win32/api/fltuser/nf-fltuser-filterinstancefindfirst)
- [FilterInstanceFindNext](https://learn.microsoft.com/windows/win32/api/fltuser/nf-fltuser-filterinstancefindnext)
- [FilterInstanceGetInformation](https://learn.microsoft.com/windows/win32/api/fltuser/nf-fltuser-filterinstancegetinformation)
- [FilterVolumeInstanceFindFirst](https://learn.microsoft.com/windows/win32/api/fltuser/nf-fltuser-filtervolumeinstancefindfirst)
- [FilterVolumeInstanceFindNext](https://learn.microsoft.com/windows/win32/api/fltuser/nf-fltuser-filtervolumeinstancefindnext)
- [FltEnumerateInstanceInformationByFilter](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltenumerateinstanceinformationbyfilter)
- [FltEnumerateInstanceInformationByVolume](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltenumerateinstanceinformationbyvolume)
- [FltGetInstanceInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltgetinstanceinformation)

The INSTANCE_AGGREGATE_STANDARD_INFORMATION structure must be aligned on a LONGLONG (8-byte) boundary. If a buffer contains two or more of these structures, the **NextEntryOffset** value in each entry falls on an 8-byte boundary.

## See also

[FilterInstanceFindFirst](https://learn.microsoft.com/windows/win32/api/fltuser/nf-fltuser-filterinstancefindfirst)

[FilterInstanceFindNext](https://learn.microsoft.com/windows/win32/api/fltuser/nf-fltuser-filterinstancefindnext)

[FilterInstanceGetInformation](https://learn.microsoft.com/windows/win32/api/fltuser/nf-fltuser-filterinstancegetinformation)

[FilterVolumeInstanceFindFirst](https://learn.microsoft.com/windows/win32/api/fltuser/nf-fltuser-filtervolumeinstancefindfirst)

[FilterVolumeInstanceFindNext](https://learn.microsoft.com/windows/win32/api/fltuser/nf-fltuser-filtervolumeinstancefindnext)

[FltEnumerateInstanceInformationByFilter](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltenumerateinstanceinformationbyfilter)

[FltEnumerateInstanceInformationByVolume](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltenumerateinstanceinformationbyvolume)

[FltGetInstanceInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltgetinstanceinformation)

[INSTANCE_BASIC_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltuserstructures/ns-fltuserstructures-_instance_basic_information)

[INSTANCE_FULL_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltuserstructures/ns-fltuserstructures-_instance_full_information)

[INSTANCE_PARTIAL_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltuserstructures/ns-fltuserstructures-_instance_partial_information)