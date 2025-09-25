# DXGK_HARDWARERESERVEDRANGES structure

## Description

The **DXGK_HARDWARERESERVEDRANGES** structure is used to store the hardware reserved memory ranges that were queried by the call the [**DXGKDDI_QUERYADAPTERINFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_queryadapterinfo).

## Members

### `NumRanges`

The number of ranges that are reserved.

### `pPhysicalRanges`

Pointer to a [**DXGK_PHYSICAL_MEMORY_RANGE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_physical_memory_range) structure that contains information about the physical memory ranges.

## Remarks

The VidMm (Video Memory Manager) validates whether the ranges returned from [**DXGKDDI_QUERYADAPTERINFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_queryadapterinfo) overlap any regions of memory used by the NTOS (Windows NT-based operating system) memory manager. This validation ensures that the driver does not accidentally report a region of physical memory that is outside the reserved range, as this would violate the security guarantees of the feature.

See [IOMMU-based GPU isolation](https://learn.microsoft.com/windows-hardware/drivers/display/iommu-based-gpu-isolation) for more information.