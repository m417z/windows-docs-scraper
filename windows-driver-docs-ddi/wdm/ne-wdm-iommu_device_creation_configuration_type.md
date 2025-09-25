## Description

Describes the configuration types that are used upon **IOMMU_DMA_DEVICE** creation depending on the device type and the system.

## Constants

### `IommuDeviceCreationConfigTypeNone`

Default no type.

### `IommuDeviceCreationConfigTypeAcpi`

Provides ACPI device specific parameters. This is currently used for ARM64 only. See [**IOMMU_DEVICE_CREATION_CONFIGURATION_ACPI**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-iommu_device_creation_configuration_acpi).

### `IommuDeviceCreationConfigTypeDeviceId`

Defines the **IommuDeviceCreationConfigTypeDeviceId** constant.

### `IommuDeviceCreationConfigTypePasid`

Defines the **IommuDeviceCreationConfigTypePasid** constant.

### `IommuDeviceCreationConfigTypeMax`

Invalid type.

## Remarks

## See also

[**IOMMU_DEVICE_CREATION_CONFIGURATION_ACPI**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-iommu_device_creation_configuration_acpi)

[**IOMMU_DEVICE_CREATION_CONFIGURATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-iommu_device_creation_configuration)

[**IOMMU_DEVICE_CREATE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-iommu_device_create)