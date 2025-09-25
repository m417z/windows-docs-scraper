# PEP_ACPI_INITIALIZE_MEMORY_RESOURCE function (pepfx.h)

## Description

The **PEP_ACPI_INITIALIZE_MEMORY_RESOURCE** function initializes a platform extension plug-in's (PEP) [PEP_ACPI_IO_MEMORY_RESOURCE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_acpi_io_memory_resource) structure.

## Parameters

### `ReadWrite` [in]

If true, indicates that the resource is read/write. Otherwise, it's read-only.

### `MinimumAddress` [in]

Specifies the minimum acceptable starting address for the IO range.

### `MaximumAddress` [in]

Specifies the maximum acceptable starting address for the IO range.

### `Alignment` [in]

Specifies the alignment granularity for the memory address assigned.

### `MemorySize` [in]

Specifies the number of bytes in the memory range.

### `Resource` [out]

A pointer to the resource. The structure behind the pointer is of type [PEP_ACPI_IO_MEMORY_RESOURCE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_acpi_io_memory_resource).

## See also

[PEP_ACPI_IO_MEMORY_RESOURCE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_acpi_io_memory_resource)