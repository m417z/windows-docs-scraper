# DEVICE_LB_PROVISIONING_DESCRIPTOR structure

## Description

The
**DEVICE_LB_PROVISIONING_DESCRIPTOR**
structure is one of the query result structures returned from an
[IOCTL_STORAGE_QUERY_PROPERTY](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-ioctl_storage_query_property) request. This
structure contains the thin provisioning capabilities for a storage device.

## Members

### `Version`

Contains the size of this structure, in bytes. The value of this member will change as members are added to
the structure.

### `Size`

Specifies the total size of the data returned, in bytes. This may include data that follows this
structure.

### `ThinProvisioningEnabled`

The thin provisioning–enabled status.

| Value | Meaning |
| --- | --- |
| 0 | Thin provisioning is disabled. |
| 1 | Thin provisioning is enabled. |

### `ThinProvisioningReadZeros`

Reads to unmapped regions return zeros.

| Value | Meaning |
| --- | --- |
| 0 | Data read from unmapped regions is undefined. |
| 1 | Reads return zeros. |

### `AnchorSupported`

Deterministic read after trim support.

| Value | Meaning |
| --- | --- |
| 0 | Deterministic read after trim is not supported. |
| 1 | Deterministic read after trim is supported. |

### `UnmapGranularityAlignmentValid`

The validity of unmap granularity alignment for the device.

| Value | Meaning |
| --- | --- |
| 0 | Unmap granularity alignment is not valid. |
| 1 | Unmap granularity alignment is valid. |

### `Reserved0`

Reserved.

### `Reserved1`

Reserved.

### `OptimalUnmapGranularity`

The optimal number of logical sectors for unmap granularity for the device.

### `UnmapGranularityAlignment`

The current value, in logical sectors, set for unmap granularity alignment on the device.

### `MaxUnmapLbaCount`

**Starting in Windows 10:** The maximum number of LBAs that can be unmapped in a single unmap command, in logical blocks.

### `MaxUnmapBlockDescriptorCount`

**Starting in Windows 10:** The maximum number of descriptors allowed in a single unmap command.

## Remarks

This structure is returned from a
[IOCTL_STORAGE_QUERY_PROPERTY](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-ioctl_storage_query_property) request when the
**PropertyId** member of
[STORAGE_PROPERTY_QUERY](https://learn.microsoft.com/windows/desktop/api/winioctl/ns-winioctl-storage_property_query) is set to
**StorageDeviceLBProvisioningProperty**.

If **UnmapGranularityAlignmentValid** = 0, then any code using
**UnmapGranularityAlignment** should assume it has a value of 0.

## See also

[Disk Management Structures](https://learn.microsoft.com/windows/desktop/FileIO/disk-management-structures)

[IOCTL_STORAGE_QUERY_PROPERTY](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-ioctl_storage_query_property)

[STORAGE_PROPERTY_QUERY](https://learn.microsoft.com/windows/desktop/api/winioctl/ns-winioctl-storage_property_query)