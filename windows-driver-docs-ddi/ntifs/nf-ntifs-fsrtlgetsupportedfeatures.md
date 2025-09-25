# FsRtlGetSupportedFeatures function

## Description

The **FsRtlGetSupportedFeatures** routine returns the supported features of a volume attached to the specified device object.

## Parameters

### `DeviceObject` [in]

The target device object attached to a volume.

### `SupportedFeatures` [out]

A pointer to a caller-supplied **ULONG** value. On return, this value contains the supported feature flags for the attached volume. See Remarks.

The supported features are a bitwise OR combination of the following flags.

| Value | Meaning |
| ----- | ------- |
| **SUPPORTED_FS_FEATURES_OFFLOAD_READ** 0x01 | The volume supports offloaded read operations. |
| **SUPPORTED_FS_FEATURES_OFFLOAD_WRITE** 0x02 | The volume supports offloaded write operations. |
| **SUPPORTED_FS_FEATURES_QUERY_OPEN** 0x04 | The volume supports query open operations. |
| **SUPPORTED_FS_FEATURES_BYPASS_IO** 0x08 | The volume supports [BypassIO](https://learn.microsoft.com/windows-hardware/drivers/ifs/bypassio). This flag is available starting in Windows 11. |

## Return value

**FsRtlGetSupportedFeatures** returns **STATUS_SUCCESS** if the supported features for the volume attached to *DeviceObject* are returned successfully. Otherwise, an **NTSTATUS** value such as one of the following is returned.

| Return code | Description |
| ----------- | ----------- |
| **STATUS_FLT_VOLUME_NOT_FOUND** | No volume is found for *DeviceObject*. |
| **STATUS_FLT_INTERNAL_ERROR** | The device object specified by *DeviceObject* is not in a file system device stack. |

## Remarks

Filter Manager looks at the supported features, specified by a minifilter's **SupportedFeatures** Registry value, for every minifilter attached to the volume. Every attached minifilter must support a specific feature in order for that feature bit to be set. The **SupportedFeatures** value does not apply to file systems. Supported features ("SprtFtrs") can be queried by running ```fltmc instances``` in an elevated command prompt window.