## Description

**IOMMU_DEVICE_CREATION_CONFIGURATION_ACPI** provides the ACPI-specific configuration parameters of a [**IOMMU_DEVICE_CREATION_CONFIGURATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-iommu_device_creation_configuration) structure, which is provided for creation of an ACPI-type **IOMMU_DMA_DEVICE**.

## Members

### `InputMappingBase`

Provides the input mapping base for the device's desired stream.

### `MappingsCount`

Provides the count of mappings beginning at the base.

## Remarks

This is required for ACPI devices on ARM64 systems.

## See also

[**IOMMU_DEVICE_CREATION_CONFIGURATION_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-iommu_device_creation_configuration_type)

[**IOMMU_DEVICE_CREATION_CONFIGURATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-iommu_device_creation_configuration)

[**IOMMU_DEVICE_CREATE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-iommu_device_create)