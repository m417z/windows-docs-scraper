# _STI_DEVICE_INFORMATIONW structure

## Description

The STI_DEVICE_INFORMATION structure is used as an output parameter for the [IStillImage::GetDeviceList](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff543784(v=vs.85)) and [IStillImage::GetDeviceInfo](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff543782(v=vs.85)) functions. It is used as an input parameter for [IStillImage::SetupDeviceParameters](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff543803(v=vs.85)).

## Members

### `dwSize`

Caller-supplied size, in bytes, of the STI_DEVICE_INFORMATION structure.

### `DeviceType`

An [STI_DEVICE_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/sti/ne-sti-_sti_device_mj_type)-typed value identifying the still image device type.

### `szDeviceInternalName`

Character array containing the device's internal name string. The string can have at most STI_MAX_INTERNAL_NAME_LENGTH characters, including the terminating null character. STI_MAX_INTERNAL_NAME_LENGTH is defined in *Sti.h*.

### `DeviceCapabilities`

Structure of type [STI_DEV_CAPS](https://learn.microsoft.com/windows-hardware/drivers/ddi/sti/ns-sti-_sti_dev_caps).

### `dwHardwareConfiguration`

Type of bus connection. The following constants are defined in *Sti.h*:

STI_HW_CONFIG_PARALLEL

STI_HW_CONFIG_SCSI

STI_HW_CONFIG_SERIAL

STI_HW_CONFIG_USB

STI_HW_CONFIG_UNKNOWN

### `pszVendorDescription`

Pointer to a vendor identification string, obtained from the [INF Manufacturer Section](https://learn.microsoft.com/windows-hardware/drivers/install/inf-manufacturer-section) of the device's INF file.

### `pszDeviceDescription`

Pointer to a device description string, obtained from the [INF Models Section](https://learn.microsoft.com/windows-hardware/drivers/install/inf-models-section) of the device's INF file.

### `pszPortName`

Pointer to a string identifying the device's port.

### `pszPropProvider`

Pointer to a string containing the file name and entry point of a DLL for adding device-specific property sheet pages to Control Panel. Obtained from the **PropertyPages** entry in the device's INF file.

### `pszLocalName`

Pointer to the local device name the user supplied during installation, for use in displays.