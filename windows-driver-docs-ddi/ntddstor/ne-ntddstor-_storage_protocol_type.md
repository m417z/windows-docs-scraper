# _STORAGE_PROTOCOL_TYPE enumeration

## Description

This enumeration is used to define the different storage command protocols that are used between software and hardware.

## Constants

### `ProtocolTypeUnknown`

Unknown protocol type.

### `ProtocolTypeScsi`

SCSI protocol type.

### `ProtocolTypeAta`

ATA protocol type.

### `ProtocolTypeNvme`

NVMe protocol type.

### `ProtocolTypeSd`

SD protocol type.

### `ProtocolTypeUfs`

UFS protocol type.

### `ProtocolTypeProprietary`

 Vendor-specific protocol type.

### `ProtocolTypeMaxReserved`

Reserved.

## Remarks

Protocol types that are 128 (0x80) and above in value are reserved for Microsoft use.