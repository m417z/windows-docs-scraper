## Description

The WHEA_GENERIC_ERROR_DESCRIPTOR_V2 structure describes a generic error source.

## Members

### `Type`

The type of error source descriptor. This member is always set to WHEA_ERROR_SOURCE_DESCRIPTOR_TYPE_GENERIC_V2.

### `Reserved`

Reserved for system use.

### `Enabled`

A Boolean value that indicates if the error source is enabled.

### `ErrStatusBlockLength`

The size, in bytes, of the block of error status registers that contain the error data for the error source.

### `RelatedErrorSourceId`

The identifier of the related error source. If the generic error source does not relate back to another error source, this member is not used.

### `ErrStatusAddressSpaceID`

The address space of the address that is specified in the **ErrStatusAddress** member.

### `ErrStatusAddressBitWidth`

The size, in bits, of the register at the address that is specified in the **ErrStatusAddress** member.

### `ErrStatusAddressBitOffset`

The offset, in bits, of the register at the address that is specified in the **ErrStatusAddress** member.

### `ErrStatusAddressAccessSize`

The access size for reading the register at the address that is specified in the **ErrStatusAddress** member.

### `ErrStatusAddress`

The 64-bit address of a register that contains the physical address of a block of memory that contains the error status data for the error source. This block of memory must reside in firmware reserved memory so that it is not reclaimed by the operating system's memory manager. The error status data contained in this block of memory is described by a [WHEA_GENERIC_ERROR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_generic_error) structure.

### `Notify`

A [WHEA_NOTIFICATION_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_notification_descriptor) structure that describes the notification mechanism that is used by the error source.

### `ReadAckAddressSpaceID`

The address space of the address that is specified in the **ReadAckAddress** member.

### `ReadAckAddressBitWidth`

The size, in bits, of the register at the address that is specified in the **ReadAckAddress** member.

### `ReadAckAddressBitOffset`

The offset, in bits, of the register at the address that is specified in the **ReadAckAddress** member.

### `ReadAckAddressAccessSize`

The access size for reading the register at the address that is specified in the **ReadAckAddress** member.

### `ReadAckAddress`

The 64-bit address of a register that is used to notify the RAS controller that Windows has processed the Error Status Block.

### `ReadAckPreserveMask`

Contains a mask of bits to preserve when writing the Read Ack register.

### `ReadAckWriteMask`

Contains a mask of bits to set when writing the Read Ack register.

## Remarks

This structure corresponds to the Generic Hardware Error Source version 2 (GHESv2) structure that is defined in [Advanced Configuration and Power Interface (ACPI) Specification version 6.2](https://uefi.org/sites/default/files/resources/ACPI%206_2_A_Sept29.pdf).

## See also

[WHEA_ERROR_SOURCE_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_error_source_descriptor)

[**WHEA_GENERIC_ERROR_DESCRIPTOR**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_generic_error_descriptor)