## Description

An interface structure that allows device drivers to interface with the IOMMU functions that perform device domain operations.

## Members

### `Size`

The size (in bytes) of the interface structure.

### `Version`

The interface version number that determines the set of interface functions that are provided by this interface structure.

### `V1`

A [**DMA_IOMMU_INTERFACE_V1**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-dma_iommu_interface_v1) structure that specifies the set of Version 1 (V1) IOMMU interface functions.

These are the same set of functions as those provided by the deprecated [**DMA_IOMMU_INTERFACE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_dma_iommu_interface) structure.

### `V2`

A [**DMA_IOMMU_INTERFACE_V2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-dma_iommu_interface_v2) structure that specifies the set of Version 2 (V2) IOMMU interface functions.

### `V3`

A [**DMA_IOMMU_INTERFACE_V3**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-dma_iommu_interface_v3) structure that specifies the set of Version 3 (V3) IOMMU interface functions.

## Remarks

Use this structure for V1 functions instead of the deprecated [**DMA_IOMMU_INTERFACE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_dma_iommu_interface) structure.

## See also

[**DMA_IOMMU_INTERFACE_V1**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-dma_iommu_interface_v1)

[**DMA_IOMMU_INTERFACE_V2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-dma_iommu_interface_v2)

[**IoGetIommuInterfaceEx**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iogetiommuinterfaceex)