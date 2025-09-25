# PEP_ACPI_INITIALIZE_EXTENDED_MEMORY_RESOURCE function (pep_x.h)

## Description

The **PEP_ACPI_INITIALIZE_EXTENDED_MEMORY_RESOURCE** function initializes a platform extension plug-in's (PEP) [PEP_ACPI_EXTENDED_ADDRESS](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_acpi_extended_address) structure.

## Parameters

### `ResourceUsage` [in]

This parameter is copied into the **GeneralFlags** member of the initialized [PEP_ACPI_EXTENDED_ADDRESS](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_acpi_extended_address) structure.

### `Decode` [in]

When set, indicates that this bridge subtractively decodes the address. This applies to top level bridges only.

When not set, indicates that this bridge positively decodes this address.

### `IsMinFixed` [in]

When set, indicates that the minimum address is fixed.

### `IsMaxFixed` [in]

When set, indicates that the maximum address is fixed.

### `Cacheable` [in]

The caching flag for the resource.

| Value | Meaning |
| --- | --- |
| 0 | Indicates the memory is non-cacheable. |
| 1 | Indicates the memory is cacheable. |
| 2 | Indicates the memory is cacheable and supports write combining. |
| 3 | The memory is cacheable and prefetchable. |

### `ReadWrite` [in]

When true, indicates that the resource is available for read/write access. Otherwise, it's read-only.

### `AddressGranularity` [in]

A bit mask indicating which bits have been decoded.

### `AddressMinimum` [in]

For bridges that translate addresses, this indicates the minimum starting address on the secondary side of the bridge.

### `AddressMaximum` [in]

For bridges that translate addresses, this indicates the maximum starting address on the secondary side of the bridge.

### `AddressTranslation` [in]

For bridges that translate addresses across the bridge, this is the
address on the primary side.

### `RangeLength` [in]

The length of the address range.

### `TypeSpecificAttributes` [in]

The type-specific attributes for this resource.

### `DescriptorName` [in]

The name of the resource descriptor.

### `MemoryRangeType` [in]

This parameter identifies the type of memory range provided by this resource.

| Value | Meaning |
| --- | --- |
| 0 | Address range memory: This range is available RAM usable by the operating system. |
| 1 | Address range reserved: This range of addresses is in use or reserved by the system and is not to be included in the allocatable memory pool of the operating system's memory manager. |
| 2 | Address range ACPI: ACPI Reclaim Memory. This range is available RAM usable by the OS after it reads the ACPI tables. |
| 3 | Address Range NVS: ACPI NVS Memory. This range of addresses is in use or reserved by the system and must not be used by the operating system. This range is required to be saved and restored across an NVS sleep. |

### `TranslationTypeNonStatic`

When true, indicates that the resource uses type translation. Otherwise, it uses type-static translation.

### `Resource` [out]

This is cast to *[PEP_ACPI_EXTENDED_ADDRESS](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_acpi_extended_address).

## See also

[PEP_ACPI_EXTENDED_ADDRESS](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_acpi_extended_address)