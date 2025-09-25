## Description

The **IOMMU_DEVICE_CREATION_CONFIGURATION_PASID** structure provides PASID-specific configuration parameters for an [**IOMMU_DEVICE_CREATION_CONFIGURATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-iommu_device_creation_configuration) structure, which is used during the creation of an IOMMU_DMA_DEVICE with PASID support.

## Members

### `ConfigType`

A [**IOMMU_PASID_CONFIGURATION_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-iommu_pasid_configuration_type) value that indicates the type of PASID support.

### `SuppressPasidFaults`

A **BOOLEAN** value that specifies whether faults related to PASID-tagged DMA traffic should be silenced. When TRUE, PASID faults are suppressed. When FALSE (the default), faults are fatal and will be reported.

## Remarks

This structure is used when creating an IOMMU device that requires PASID (Process Address Space Identifier) support. It specifies both the type of PASID configuration and fault handling behavior.

The **ConfigType** field determines whether the device will support only a default PASID or full PASID-tagged DMA capabilities. The **SuppressPasidFaults** field allows drivers to control fault reporting behavior for PASID-related operations.

## See also

[**IOMMU_PASID_CONFIGURATION_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-iommu_pasid_configuration_type)

[**IOMMU_DEVICE_CREATION_CONFIGURATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-iommu_device_creation_configuration)

[**IOMMU_DEVICE_CREATE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-iommu_device_create)

[**IOMMU_PASID_DEVICE_CREATE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-iommu_pasid_device_create)