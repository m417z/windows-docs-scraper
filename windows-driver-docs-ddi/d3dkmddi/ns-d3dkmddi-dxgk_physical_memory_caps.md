## Description

The **DXGK_PHYSICAL_MEMORY_CAPS** structure provides information about the driver's physical memory restrictions.

## Members

### `HighestVisibleAddress`

The highest visible physical memory address. If multiple linked physical adapters have different values for their highest visible address, the driver should report the minimum value of all physical adapters.

## Remarks

The driver fills in this structure when *Dxgkernel* calls [**DxgkDdiQueryAdapterInfo**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_queryadapterinfo) with a [**DXGK_QUERYADAPTERINFOTYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ne-d3dkmddi-_dxgk_queryadapterinfotype) value of **DXGKQAITYPE_PHYSICAL_MEMORY_CAPS**.

To indicate logical DMA remapping support, the driver must also fill in [**DXGK_IOMMU_CAPS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-dxgk_iommu_caps) accordingly.

See [IOMMU DMA remapping](https://learn.microsoft.com/windows-hardware/drivers/display/iommu-dma-remapping) for more information.

## See also

[**DXGK_IOMMU_CAPS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-dxgk_iommu_caps)

[**DXGK_QUERYADAPTERINFOTYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ne-d3dkmddi-_dxgk_queryadapterinfotype)

[**DXGK_VIDMMCAPS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_vidmmcaps)

[**DxgkDdiQueryAdapterInfo**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_queryadapterinfo)