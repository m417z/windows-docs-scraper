## Description

Contains information about an IOMMU DMA device's PASID (Process Address Space Identifier) capabilities and configuration. This structure is returned by the [**IOMMU_DEVICE_QUERY_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-iommu_device_query_information) function.

## Members

### `DefaultPasidEnabled`

A **BOOLEAN** value that indicates whether the device has a default PASID enabled. When TRUE, the device operates with a default PASID for DMA operations. When FALSE, the device does not have a default PASID configured.

### `PasidTaggedDmaEnabled`

A **BOOLEAN** value that indicates whether the device supports PASID-tagged DMA operations. When TRUE, the device can perform DMA operations with PASID tags, enabling multiple address spaces. When FALSE, the device does not support PASID-tagged DMA.

### `PasidFaultsSuppressed`

A **BOOLEAN** value that indicates whether PASID-related faults are suppressed for this device. When TRUE, PASID faults are suppressed and will not be reported. When FALSE, PASID faults will be reported normally.

## Remarks

This structure provides essential information about a device's PASID capabilities, which are used for advanced memory management scenarios.

## See also

[**IOMMU_DEVICE_QUERY_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-iommu_device_query_information)

[**IOMMU_PASID_DEVICE_CREATE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-iommu_pasid_device_create)

[**DMA_IOMMU_INTERFACE_V3**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-dma_iommu_interface_v3)