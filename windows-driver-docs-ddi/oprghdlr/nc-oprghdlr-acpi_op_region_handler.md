## Description

An ACPI_OP_REGION_HANDLER-typed routine is supplied by an ACPI device function driver to provide access by the [ACPI driver](https://learn.microsoft.com/windows-hardware/drivers/kernel/acpi-driver) to the device's operation region.

## Parameters

### `AccessType`

Specifies one of the following access types:

| Access type | Description |
|---|---|
| ACPI_OPREGION_WRITE | Write to the operation region memory buffer. |
| ACPI_OPREGION_READ | Read from the operation region memory buffer. |

### `OperationRegionObject`

Specifies the operation region object returned by **RegisterOpRegionHandler** for the operation region handler.

### `Address`

Specifies a byte offset in the operation region memory buffer. Depending on the access type, data is transferred to or from this memory location.

### `Size`

Specifies the number of bytes to access.

### `Data`

Pointer to the data buffer supplied by the ACPI driver that is associated with the access. For a read access, bytes are transferred from the operation region memory buffer to the data buffer. For a write access, bytes are transferred from the data buffer to the operation region memory buffer.

### `Context`

Pointer to the same operation region context that the function driver specified when it registered the operation region handler.

### `CompletionHandler`

Reserved for internal use.

### `CompletionContext`

Reserved for internal use.

## Return value

Returns one of the following status values:

| Return code | Description |
|---|---|
| STATUS_SUCCESS | The access was successful. |
| STATUS_INVALID_DEVICE_REQUEST | The access type is invalid. |
| STATUS_Xxx | An internal error occurred. |

## Remarks

When the ACPI driver calls an operation region handler, it specifies values for *Address* and *Size* that ensure that the access is within the operation region that is defined in the ACPI BIOS for the ACPI device. The ACPI device function driver must ensure that the operation region memory buffer it allocates is at least as large, in bytes, as the operation region defined for the ACPI device.

For more information about operation region handlers, see [Supporting an Operation Region](https://learn.microsoft.com/windows-hardware/drivers/acpi/supporting-an-operation-region).

An ACPI_OP_REGION_HANDLER-typed routine runs at the caller's IRQL.

For detailed information about constraints on operation regions, see the [Advanced Configuration and Power Interface (ACPI) Specification](https://uefi.org/specifications).

## See also

[DeRegisterOpRegionHandler](https://learn.microsoft.com/windows-hardware/drivers/ddi/oprghdlr/nf-oprghdlr-deregisteropregionhandler)