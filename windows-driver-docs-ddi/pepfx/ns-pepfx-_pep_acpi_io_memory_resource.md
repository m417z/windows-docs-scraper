# _PEP_ACPI_IO_MEMORY_RESOURCE structure (pepfx.h)

## Description

The **PEP_ACPI_IO_MEMORY_RESOURCE** structure describes an ACPI IO port descriptor resource.

## Members

### `Type`

A [PEP_ACPI_RESOURCE_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ne-pepfx-_pep_acpi_resource_type) enumeration value that identifies the resource type for this ACPI resource.

### `Information`

If bit 0 is a 1, this indicates that the logical device decodes 16-bit addresses. If bit 0 is 0, this indicates that the logical device only decodes the first 10 bits of the address.

Bits 1 to 7 of this member are reserved and must be set to zero.

### `MinimumAddress`

Specifies the minimum acceptable starting address for the IO range.

### `MaximumAddress`

Specifies the maximum acceptable starting address for the IO range.

### `Alignment`

Specifies the alignment granularity for the IO address assigned.

### `Length`

Specifies the number of bytes in the IO range.

## See also

[PEP_ACPI_RESOURCE_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ne-pepfx-_pep_acpi_resource_type)