# STORAGE_ADAPTER_DESCRIPTOR structure

## Description

Used with the
[IOCTL_STORAGE_QUERY_PROPERTY](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-ioctl_storage_query_property) control code to
retrieve the storage adapter descriptor data for a device.

## Members

### `Version`

Contains the size of this structure, in bytes. The value of this member will change as members are added to
the structure.

### `Size`

Specifies the total size of the data returned, in bytes. This may include data that follows this
structure.

### `MaximumTransferLength`

Specifies the maximum number of bytes the storage adapter can transfer in a single operation.

### `MaximumPhysicalPages`

Specifies the maximum number of discontinuous physical pages the storage adapter can manage in a single
transfer (in other words, the extent of its scatter/gather support).

### `AlignmentMask`

Specifies the storage adapter's alignment requirements for transfers. The alignment mask indicates
alignment restrictions for buffers required by the storage adapter for transfer operations. Valid mask values
are also restricted by characteristics of the memory managers on different versions of Windows.

| Value | Meaning |
| --- | --- |
| 0 | Buffers must be aligned on **BYTE** boundaries. |
| 1 | Buffers must be aligned on **WORD** boundaries. |
| 3 | Buffers must be aligned on **DWORD32** boundaries. |
| 7 | Buffers must be aligned on **DWORD64** boundaries. |

### `AdapterUsesPio`

If this member is **TRUE**, the storage adapter uses programmed I/O (PIO) and
requires the use of system-space virtual addresses mapped to physical memory for data buffers. When this member
is **FALSE**, the storage adapter does not use PIO.

### `AdapterScansDown`

If this member is **TRUE**, the storage adapter scans down for BIOS devices, that is,
the storage adapter begins scanning with the highest device number rather than the lowest. When this member is
**FALSE**, the storage adapter begins scanning with the lowest device number. This member
is reserved for legacy miniport drivers.

### `CommandQueueing`

If this member is **TRUE**, the storage adapter supports SCSI tagged queuing and/or
per-logical-unit internal queues, or the non-SCSI equivalent. When this member is
**FALSE**, the storage adapter neither supports SCSI-tagged queuing nor per-logical-unit
internal queues.

### `AcceleratedTransfer`

If this member is **TRUE**, the storage adapter supports synchronous transfers as a
way of speeding up I/O. When this member is **FALSE**, the storage adapter does not
support synchronous transfers as a way of speeding up I/O.

### `BusType`

Specifies a value of type [STORAGE_BUS_TYPE](https://learn.microsoft.com/windows/desktop/api/winioctl/ne-winioctl-storage_bus_type) that
indicates the type of the bus to which the device is connected.

### `BusMajorVersion`

Specifies the major version number, if any, of the storage adapter.

### `BusMinorVersion`

Specifies the minor version number, if any, of the storage adapter.

### `SrbType`

Specifies the SCSI request block (SRB) type used by the HBA.

| Value | Meaning |
| --- | --- |
| **SRB_TYPE_SCSI_REQUEST_BLOCK** | The HBA uses SCSI request blocks. |
| **SRB_TYPE_STORAGE_REQUEST_BLOCK** | The HBA uses extended SCSI request blocks. |

This member is valid starting with Windows 8.

### `AddressType`

Specifies the address type of the HBA.

| Value | Meaning |
| --- | --- |
| **STORAGE_ADDRESS_TYPE_BTL8** | The HBA uses 8-bit bus, target, and LUN addressing. |

This member is valid starting with Windows 8.

## See also

[Disk Management Structures](https://learn.microsoft.com/windows/desktop/FileIO/disk-management-structures)

[IOCTL_STORAGE_QUERY_PROPERTY](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-ioctl_storage_query_property)

[STORAGE_ADAPTER_DESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/winioctl/ns-winioctl-storage_adapter_descriptor)

[STORAGE_DESCRIPTOR_HEADER](https://learn.microsoft.com/windows/desktop/api/winioctl/ns-winioctl-storage_descriptor_header)

[STORAGE_DEVICE_ID_DESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/winioctl/ns-winioctl-storage_device_id_descriptor)