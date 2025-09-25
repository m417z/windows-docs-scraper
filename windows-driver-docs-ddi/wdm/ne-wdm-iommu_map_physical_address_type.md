## Description

The **IOMMU_MAP_PHYSICAL_ADDRESS_TYPE** enum indicates the format of the physical address described in an [**IOMMU_MAP_PHYSICAL_ADDRESS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-iommu_map_physical_address) structure.

## Constants

### `MapPhysicalAddressTypeMdl`

The physical address to be mapped is described by a MDL.

### `MapPhysicalAddressTypeContiguousRange`

The physical address to be mapped is physically contiguous and is described by a base and size.

### `MapPhysicalAddressTypePfn`

The physical address is described by a PFN array.

### `MapPhysicalAddressTypeMax`

Invalid physical address format.

## Remarks

## See also

[IOMMU_MAP_PHYSICAL_ADDRESS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-iommu_map_physical_address)

[IOMMU_MAP_LOGICAL_RANGE_EX](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-iommu_map_logical_range_ex)

[IOMMU_MAP_IDENTITY_RANGE_EX](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-iommu_map_identity_range_ex)