## Description

This routine set the device fault reporting state on a device already attached to a domain.

## Parameters

### `DmaDevice`

[*In*] A pointer to the **IOMMU_DMA_DEVICE**.

### `InputMappingIdBase`

[*In*] The base input mapping ID for the device.

### `Enable`

[*In*] A **BOOLEAN** indicating whether to enable fault reporting for the device.

### `FaultConfig`

[*In*, optional] An optional pointer to [**DEVICE_FAULT_CONFIGURATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_device_fault_configuration). Only used when enabling fault reporting.

## Return value

**STATUS_NOT_IMPLEMENTED** always.

## Remarks

This is currently not implemented and will return as such.

## See also

[**IOMMU_DOMAIN_ATTACH_DEVICE_EX**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-iommu_domain_attach_device_ex)

[**DMA_IOMMU_INTERFACE_V2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-dma_iommu_interface_v2)

[**DMA_IOMMU_INTERFACE_EX**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-dma_iommu_interface_ex)