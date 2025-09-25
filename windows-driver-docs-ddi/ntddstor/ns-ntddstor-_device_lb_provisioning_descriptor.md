# DEVICE_LB_PROVISIONING_DESCRIPTOR structure

## Description

The **DEVICE_LB_PROVISIONING_DESCRIPTOR** structure is one of the query result structures returned from an [**IOCTL_STORAGE_QUERY_PROPERTY**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ni-ntddstor-ioctl_storage_query_property) request. This structure contains the thin provisioning capabilities for a storage device.

## Members

### `Version`

The version of this structure.

### `Size`

The size of this structure. This is set to ```sizeof(DEVICE_LB_PROVISIONING_DESCRIPTOR)```.

### `ThinProvisioningEnabled`

The thin provisioning–enabled status.

| Value | Meaning |
| ----- | ------- |
| 0 | Thin provisioning is disabled. |
| 1 | Thin provisioning is enabled. |

### `ThinProvisioningReadZeros`

Reads to unmapped regions return zeros.

| Value | Meaning |
| ----- | ------- |
| 0 | Data read from unmapped regions is undefined. |
| 1 | Reads return zeros. |

### `AnchorSupported`

Support for the anchored LBA mapping state.

| Value | Meaning |
| ----- | ------- |
| 0 | The anchored LBA mapping state is not supported. |
| 1 | The anchored LBA mapping state is supported. |

### `UnmapGranularityAlignmentValid`

The validity of unmap granularity alignment for the device.

| Value | Meaning |
| ----- | ------- |
| 0 | Unmap granularity alignment is not valid. |
| 1 | Unmap granularity alignment is valid. |

### `GetFreeSpaceSupported`

Indicates support for [**DeviceDsmAction_GetFreeSpace**](https://learn.microsoft.com/windows-hardware/drivers/storage/device-dsm-action-descriptions).

| Value | Meaning |
| ----- | ------- |
| 0 | **DeviceDsmAction_GetFreeSpace** is not supported. |
| 1 | **DeviceDsmAction_GetFreeSpace** is supported. |

### `MapSupported`

Indicates support for [**DeviceDsmAction_Map**](https://learn.microsoft.com/windows-hardware/drivers/storage/device-dsm-action-descriptions).

| Value | Meaning |
| ----- | ------- |
| 0 | **DeviceDsmAction_Map** is not supported. |
| 1 | **DeviceDsmAction_Map** is supported. |

### `Reserved1`

Reserved; do not use.

### `OptimalUnmapGranularity`

The optimal number of blocks for unmap granularity for the device.

### `UnmapGranularityAlignment`

The current value, in blocks, set for unmap granularity alignment on the device. The value **UnmapGranularityAlignmentValid** indicates the validity of this member.

### `MaxUnmapLbaCount`

Maximum amount of LBAs that can be unmapped in a single UNMAP command, in units of logical blocks. Valid starting in Windows 10.

### `MaxUnmapBlockDescriptorCount`

Maximum number of descriptors allowed in a single UNMAP command. Valid starting in Windows 10.

## Remarks

This structure is returned in the system buffer from a [**IOCTL_STORAGE_QUERY_PROPERTY**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ni-ntddstor-ioctl_storage_query_property) request when the **PropertyId** member of [**STORAGE_PROPERTY_QUERY**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-_storage_property_query) is set to **StorageDeviceLBProvisioningProperty**.

The **DEVICE_LB_PROVISIONING_DESCRIPTOR** structure is written to the system buffer, **Irp->AssociatedIrp.SystemBuffer**, with a value of **sizeof**(DEVICE_LB_PROVISIONING_DESCRIPTOR) set in **Parameters.DeviceIoControl.OutputBufferLength** for the current IRP stack location.

If **UnmapGranularityAlignmentValid** is 0, then any code using **UnmapGranularityAlignment** should assume it has a value of 0.

If the underlying storage device is a SCSI device, unmapping capability can be queried. If the **TrimEnabled** member of the [**DEVICE_TRIM_DESCRIPTOR**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-_device_trim_descriptor) structure is TRUE, UNMAP is supported. The **DEVICE_TRIM_DESCRIPTOR** structure is returned in the system buffer from a [**IOCTL_STORAGE_QUERY_PROPERTY**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ni-ntddstor-ioctl_storage_query_property) request when the **PropertyId** member of [**STORAGE_PROPERTY_QUERY**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-_storage_property_query) is set to **StorageDeviceTrimProperty**.

## See also

[**IOCTL_STORAGE_QUERY_PROPERTY**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ni-ntddstor-ioctl_storage_query_property)

[**STORAGE_PROPERTY_QUERY**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-_storage_property_query)