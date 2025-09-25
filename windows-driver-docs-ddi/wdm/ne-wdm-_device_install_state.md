# _DEVICE_INSTALL_STATE enumeration

## Description

The **DEVICE_INSTALL_STATE** enumeration describes a device's installation state.

## Constants

### `InstallStateInstalled`

The device is installed.

### `InstallStateNeedsReinstall`

The system will try to reinstall the device on a later enumeration.

### `InstallStateFailedInstall`

The device did not install properly.

### `InstallStateFinishInstall`

The installation of this device is not yet complete.

## Remarks

The [IoGetDeviceProperty](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iogetdeviceproperty) routine supplies a **DEVICE_INSTALL_STATE** enumeration value when a driver requests **DevicePropertyInstallState**. The operating system uses the value as a hint about the install state of the device.

## See also

[DEVICE_REGISTRY_PROPERTY](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-device_registry_property)

[IoGetDeviceProperty](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iogetdeviceproperty)