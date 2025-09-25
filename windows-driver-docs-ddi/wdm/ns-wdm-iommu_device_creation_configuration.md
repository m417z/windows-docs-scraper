## Description

**IOMMU_DEVICE_CREATION_CONFIGURATION** describes a configuration or list of configurations to be used as part of creation and initialization of an **IOMMU_DMA_DEVICE**.

## Members

### `NextConfiguration`

Optional list to provide additional configurations.

### `ConfigType`

An enum describing which configuration is represented. See [**IOMMU_DEVICE_CREATION_CONFIGURATION_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-iommu_device_creation_configuration_type).

### `Acpi`

If `(ConfigType == IommuDeviceCreationConfigTypeAcpi)`, provides the input parameters necessary for device creation. See [**IOMMU_DEVICE_CREATION_CONFIGURATION_ACPI**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-iommu_device_creation_configuration_acpi)

### `DeviceId`

Defines the **PVOID** member **DeviceId**.

### `Pasid`

Defines the **IOMMU_DEVICE_CREATION_CONFIGURATION_PASID** member **Pasid**.

## Remarks

If the device is an ACPI device on an ARM64 system, then an **IOMMU_DEVICE_CREATION_CONFIGURATION** structure must be provided during device creation, `ConfigType = IommuDeviceCreationConfigTypeAcpi`, and ACPI-specific parameters must be provided through [**IOMMU_DEVICE_CREATION_CONFIGURATION_ACPI**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-iommu_device_creation_configuration_acpi) in the `Acpi` field.

## See also

[**IOMMU_DEVICE_CREATION_CONFIGURATION_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-iommu_device_creation_configuration_type)

[**IOMMU_DEVICE_CREATION_CONFIGURATION_ACPI**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-iommu_device_creation_configuration_acpi)

[**IOMMU_DEVICE_CREATE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-iommu_device_create)