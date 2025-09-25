## Description

> [!CAUTION]
> `IoGetIommuInterface` has been deprecated in Windows 10, version 2103 and has been replaced by [IoGetIommuInterfaceEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iogetiommuinterfaceex).

Retrieves a pointer to the interface that contains pointers to IOMMU routines.

## Parameters

### `Version`

The interface version.

### `InterfaceOut`

A pointer to a [**DMA_IOMMU_INTERFACE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_dma_iommu_interface) that contains pointers to IOMMU callback routines for device domain operations.

## Return value

This function returns NTKERNELAPI NTSTATUS.

## Remarks

## See also

[**DMA_IOMMU_INTERFACE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_dma_iommu_interface)

[IoGetIommuInterfaceEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iogetiommuinterfaceex)