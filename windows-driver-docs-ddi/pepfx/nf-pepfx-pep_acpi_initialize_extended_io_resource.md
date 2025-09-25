# PEP_ACPI_INITIALIZE_EXTENDED_IO_RESOURCE function (pepfx.h)

## Description

The **PEP_ACPI_INITIALIZE_EXTENDED_IO_RESOURCE** function initializes a platform extension plug-in's (PEP) [PEP_ACPI_EXTENDED_ADDRESS](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_acpi_extended_address) structure.

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

### `ISARanges` [in]

This parameter is copied into the **TypeSpecificFlags** member of the initialized [PEP_ACPI_EXTENDED_ADDRESS](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_acpi_extended_address) structure.

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

### `TranslationTypeNonStatic` [in]

When true, indicates that the resource uses type translation. Otherwise, it uses type-static translation.

### `TanslationSparseDensity` [in]

When false, indicates that this is a dense translation. Otherwise, it is sparse.

### `Resource` [out]

This is cast to *[PEP_ACPI_EXTENDED_ADDRESS](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_acpi_extended_address).

## See also

[PEP_ACPI_EXTENDED_ADDRESS](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_acpi_extended_address)