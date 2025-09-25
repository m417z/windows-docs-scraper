## Description

The **DXGK_IOMMU_CAPS** structure is used to indicate whether a driver supports IOMMU linear remapping.

## Members

### `IommuIsolationSupported`

Indicates that the driver supports IOMMU isolation, and fully utilizes the IOMMU callback API to map driver-allocated memory objects to the IOMMU domain. This field mimics [**DXGK_DRIVERCAPS.MemoryManagementCaps.IOMMUSecureModeSupported**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_vidmmcaps). *Dxgkrnl* expects these capabilities to match.

### `IommuIsolationRequired`

Indicates that the IOMMU is required for the hardware to function correctly and safely. If an IOMMU is not present on the system or a domain cannot be attached to the device, the device will not start. This field mimics [**DXGK_DRIVERCAPS.MemoryManagementCaps.IOMMUSecureModeRequired**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_vidmmcaps). *Dxgkrnl* expects these capabilities to match.

### `DmaRemappingSupported`

Indicates that linear remapping is supported by the driver, and not just the 1:1 mappings used for standard isolation. If multiple linked physical adapters have different values for their highest visible address, the driver should report the minimum value of all physical adapters.

### `Reserved`

Reserved; do not use.

### `Value`

An alternative method to access the bits.

## Remarks

The driver fills in this structure when *Dxgkrnl* calls [**DxgkDdiQueryAdapterInfo**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_queryadapterinfo) with a [**DXGK_QUERYADAPTERINFOTYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ne-d3dkmddi-_dxgk_queryadapterinfotype) value of **DXGKQAITYPE_IOMMU_CAPS**. *Dxgkrnl* will call **DxgkDdiQueryAdapterInfo** after [**DxgkddiAddDevice**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_add_device) has been called for all physical adapters, but before [**DxgkddiStartDevice**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_start_device). The driver is expected to know about all linked physical adapters at this time.

To indicate logical DMA remapping support, the driver must also fill in [**DXGK_PHYSICAL_MEMORY_CAPS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-dxgk_physical_memory_caps) accordingly.

For more information, see [IOMMU DMA remapping](https://learn.microsoft.com/windows-hardware/drivers/display/iommu-dma-remapping).

## See also

[**DXGK_PHYSICAL_MEMORY_CAPS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-dxgk_physical_memory_caps)

[**DXGK_QUERYADAPTERINFOTYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ne-d3dkmddi-_dxgk_queryadapterinfotype)

[**DXGK_VIDMMCAPS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_vidmmcaps)

[**DxgkddiAddDevice**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_add_device)

[**DxgkDdiQueryAdapterInfo**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_queryadapterinfo)

 [**DxgkddiStartDevice**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_start_device)