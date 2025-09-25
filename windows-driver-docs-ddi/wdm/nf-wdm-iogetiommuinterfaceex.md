## Description

Retrieves a pointer to the extended interface that contains a set of IOMMU routines.

## Parameters

### `Version`

[*In*] The interface version that determines the set of IOMMU routines that are returned.

### `Flags`

[*In*] Configuration flags for the interface. Currently unused.

### `InterfaceOut`

[*Out*] A pointer to a [**DMA_IOMMU_INTERFACE_EX**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-dma_iommu_interface_ex) structure that contains pointers to IOMMU interface routines for device domain operations.

## Return value

This function returns NTKERNELAPI NTSTATUS.

## Remarks

To use the IOMMU routines provided by the interface, the device driver must be opted into DMA remapping via the [**DmaRemappingCompatible**](https://learn.microsoft.com/windows-hardware/drivers/pci/enabling-dma-remapping-for-device-drivers) registry key value (set to 1).

This supersedes the deprecated [*IoGetIommuInterface*](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iogetiommuinterface) function. Use this Ex one for all versions of IOMMU routines.

## See also

[**DMA_IOMMU_INTERFACE_EX**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-dma_iommu_interface_ex)