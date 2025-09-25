# STORAGE_MINIPORT_DESCRIPTOR structure

## Description

Reserved for system use.

## Members

### `Version`

Contains the size of this structure, in bytes. The value of this member will change as members are added to
the structure.

### `Size`

Specifies the total size of the data returned, in bytes. This may include data that follows this
structure.

### `Portdriver`

Type of port driver as enumerated by the
[STORAGE_PORT_CODE_SET](https://learn.microsoft.com/windows/desktop/api/winioctl/ne-winioctl-storage_port_code_set) enumeration.

| Value | Meaning |
| --- | --- |
| **StoragePortCodeSetReserved**<br><br>0 | Indicates an unknown storage adapter driver type. |
| **StoragePortCodeSetStorport**<br><br>1 | Storage adapter driver is a Storport-miniport driver. |
| **StoragePortCodeSetSCSIport**<br><br>2 | Storage adapter driver is a SCSI Port-miniport driver. |

### `LUNResetSupported`

Indicates whether a LUN reset is supported.

### `TargetResetSupported`

Indicates whether a target reset is supported.

### `IoTimeoutValue`

### `ExtraIoInfoSupported`

### `Reserved0`

### `Reserved1`

## See also

[Disk Management Structures](https://learn.microsoft.com/windows/desktop/FileIO/disk-management-structures)

[STORAGE_PORT_CODE_SET](https://learn.microsoft.com/windows/desktop/api/winioctl/ne-winioctl-storage_port_code_set)