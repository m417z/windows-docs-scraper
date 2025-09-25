# _WHEA_GENERIC_ERROR_DESCRIPTOR structure

## Description

The WHEA_GENERIC_ERROR_DESCRIPTOR structure describes a generic error source.

## Members

### `Type`

The type of error source descriptor. This member is always set to WHEA_ERROR_SOURCE_DESCRIPTOR_TYPE_GENERIC.

### `Reserved`

Reserved for system use.

### `Enabled`

A Boolean value that indicates if the error source is enabled.

### `ErrStatusBlockLength`

The size, in bytes, of the block of error status registers that contain the error data for the error source.

### `RelatedErrorSourceId`

The identifier of the related error source. If the generic error source does not relate back to another error source, this member is not used.

### `ErrStatusAddressSpaceID`

The address space of the address that is specified in the **ErrStatusAddress** member. Possible values are:

#### 0x00

System memory space

#### 0x01

System I/O space

#### 0x02

PCI configuration space

#### 0x03

Embedded controller address space

#### 0x04

System management bus (SMBus) address space

#### 0x05 - 0x7E

Reserved

#### 0x7F

Functional fixed hardware address space

#### 0x80 - 0xBF

Reserved

#### 0xC0 - 0xFF

OEM defined address space

### `ErrStatusAddressBitWidth`

The size, in bits, of the register at the address that is specified in the **ErrStatusAddress** member.

### `ErrStatusAddressBitOffset`

The offset, in bits, of the register at the address that is specified in the **ErrStatusAddress** member.

### `ErrStatusAddressAccessSize`

The access size for reading the register at the address that is specified in the **ErrStatusAddress** member. Possible values are:

#### 0

Undefined

#### 1

Byte access

#### 2

Word access

#### 3

Double word access

#### 4

Quad word access

### `ErrStatusAddress`

The 64-bit address of a register that contains the physical address of a block of memory that contains the error status data for the error source. This block of memory must reside in firmware reserved memory so that it is not reclaimed by the operating system's memory manager. The error status data contained in this block of memory is described by a [WHEA_GENERIC_ERROR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_generic_error) structure.

### `Notify`

A [WHEA_NOTIFICATION_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_notification_descriptor) structure that describes the notification mechanism that is used by the error source.

## Remarks

A WHEA_GENERIC_ERROR_DESCRIPTOR structure is contained within the [WHEA_ERROR_SOURCE_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_error_source_descriptor) structure.

## See also

[WHEA_GENERIC_ERROR_DESCRIPTOR_V2](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-whea_generic_error_descriptor_v2)

[WHEA_ERROR_SOURCE_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_error_source_descriptor)

[WHEA_GENERIC_ERROR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_generic_error)

[WHEA_NOTIFICATION_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_notification_descriptor)