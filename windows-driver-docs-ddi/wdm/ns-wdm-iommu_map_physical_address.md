## Description

The **IOMMU_MAP_PHYSICAL_ADDRESS** represents a physical address that is to be mapped to a logical address. It is used by [*IOMMU_MAP_LOGICAL_RANGE_EX*](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-iommu_map_logical_range_ex) and [*IOMMU_MAP_IDENTITY_RANGE_EX*](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-iommu_map_identity_range_ex).

## Members

### `MapType`

A [**IOMMU_MAP_PHYSICAL_ADDRESS_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-iommu_map_physical_address_type) value that indicates the format the physical address is represented in.

### `Mdl`

If MapType == *MapPhysicalAddressMdl*, provides a MDL that represents the physical address.

### `Mdl.Mdl`

The pointer to the MDL that represents the physical address.

### `ContiguousRange`

If MapType == *MapPhysicalAddressContiguousRange*, provides a contiguous physical address.

### `ContiguousRange.Base`

The base address of a contiguous physical address.

### `ContiguousRange.Size`

The size, in bytes, of a contiguous physical address.

### `PfnArray`

If MapType == *MapPhysicalAddressPfn*, provides a PFN array.

### `PfnArray.PageFrame`

The pointer to the PFN array.

### `PfnArray.NumberOfPages`

The number of PFNs in the PFN array.

## Remarks

When mapping a physical address using [*IOMMU_MAP_LOGICAL_RANGE_EX*](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-iommu_map_logical_range_ex) or [*IOMMU_MAP_IDENTITY_RANGE_EX*](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-iommu_map_identity_range_ex), the physical addresses represented must be 4K page aligned and 4K page length.

## See also

[IOMMU_MAP_LOGICAL_RANGE_EX](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-iommu_map_logical_range_ex)

[IOMMU_MAP_IDENTITY_RANGE_EX](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-iommu_map_identity_range_ex)

[IOMMU_MAP_PHYSICAL_ADDRESS_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-iommu_map_physical_address_type)