# STORAGE_PORT_CODE_SET enumeration

## Description

Reserved for system use.

## Constants

### `StoragePortCodeSetReserved:0`

Indicates an unknown storage adapter driver type.

### `StoragePortCodeSetStorport:1`

Storage adapter driver is a Storport-miniport driver.

### `StoragePortCodeSetSCSIport:2`

Storage adapter driver is a SCSI Port-miniport driver.

### `StoragePortCodeSetSpaceport:3`

Storage adapter driver is the Spaceport driver.

### `StoragePortCodeSetATAport:4`

Storage adapter driver is an ATA-port miniport driver.

### `StoragePortCodeSetUSBport:5`

Storage adapter driver is the USB-storage port driver.

### `StoragePortCodeSetSBP2port:6`

Storage adapter driver is the SBP2 port driver.

### `StoragePortCodeSetSDport:7`

Storage adapter driver is an SD-port miniport driver.

## See also

* [Disk Management Enumeration Types](https://learn.microsoft.com/windows/desktop/FileIO/disk-management-enumeration-types)
* [STORAGE_MINIPORT_DESCRIPTOR](https://learn.microsoft.com/windows/win32/api/winioctl/ns-winioctl-storage_miniport_descriptor)