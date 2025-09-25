# PEP_ACPI_INITIALIZE_IOPORT_RESOURCE function (pepfx.h)

## Description

The **PEP_ACPI_INITIALIZE_IOPORT_RESOURCE** function initializes a platform extension plug-in's (PEP) [PEP_ACPI_IO_MEMORY_RESOURCE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_acpi_io_memory_resource) structure.

## Parameters

### `Decode` [in]

Specifies how to decode the resource address. If bit 0 is a 1, this indicates that the logical device decodes 16-bit addresses. If bit 0 is 0, this indicates that the logical device only decodes the first 10 bits of the address.

Bits 1 to 7 of this parameter are reserved and must be set to zero.

### `MinimumAddress` [in]

Specifies the minimum acceptable starting address for the IO range.

### `MaximumAddress` [in]

Specifies the maximum acceptable starting address for the IO range.

### `Alignment` [in]

Specifies the alignment granularity for the IO address assigned.

### `PortLength` [in]

Specifies the number of bytes in the IO range.

### `Resource` [out]

A pointer to the resource. The structure behind the pointer is of type [PEP_ACPI_IO_MEMORY_RESOURCE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_acpi_io_memory_resource).

## See also

[PEP_ACPI_IO_MEMORY_RESOURCE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_acpi_io_memory_resource)