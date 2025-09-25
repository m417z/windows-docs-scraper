## Description

The **IOMMU_PASID_CONFIGURATION_TYPE** enumeration describes the PASID support configuration types that can be enabled for an IOMMU device. PASID (Process Address Space Identifier) configuration types describe the support related to PASIDs that can be enabled.

## Constants

### `PasidConfigTypeDefaultPasidOnly`

Indicates that the created device should be configured for untagged DMA ONLY through the default PASID, without enabling the PASID capability and other support for PASID-tagged traffic.

### `PasidConfigTypePasidTaggedDma`

Indicates that the created device should be configured for PASID-tagged DMA, which will allow for creation of PASID sub-devices (for tagged DMA). This also enables the default PASID for untagged DMA.

### `PasidConfigTypeMax`

Invalid configuration type. Used for validation purposes.

## Remarks

This enumeration is used within the [**IOMMU_DEVICE_CREATION_CONFIGURATION_PASID**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-iommu_device_creation_configuration_pasid) structure to specify the type of PASID support required for a device.

The choice between `PasidConfigTypeDefaultPasidOnly` and `PasidConfigTypePasidTaggedDma` determines whether the device will support multiple address spaces or only a single default address space.

## See also

[**IOMMU_DEVICE_CREATION_CONFIGURATION_PASID**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-iommu_device_creation_configuration_pasid)

[**IOMMU_DEVICE_CREATION_CONFIGURATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-iommu_device_creation_configuration)

[**IOMMU_PASID_DEVICE_CREATE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-iommu_pasid_device_create)