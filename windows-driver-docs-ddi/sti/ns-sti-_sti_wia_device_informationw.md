# _STI_WIA_DEVICE_INFORMATIONW structure

## Description

The STI_WIA_DEVICE_INFORMATION structure contains device information.

## Members

### `dwSize`

Caller-supplied size, in bytes, of the STI_WIA_DEVICE_INFORMATION structure.

### `DeviceType`

A value of type [STI_DEVICE_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/sti/ne-sti-_sti_device_mj_type) that identifies the type of the hardware imaging device.

### `szDeviceInternalName`

Character array containing the device's internal name string, used for reference when the device object is created. The string can have at most STI_MAX_INTERNAL_NAME_LENGTH characters, including the terminating null character. STI_MAX_INTERNAL_NAME_LENGTH is defined in *Sti.h*.

### `DeviceCapabilities`

A structure of type [STI_DEV_CAPS](https://learn.microsoft.com/windows-hardware/drivers/ddi/sti/ns-sti-_sti_dev_caps).

### `dwHardwareConfiguration`

Type of bus connection. This value can be one of the following constants, which are defined in *Sti.h*:

STI_HW_CONFIG_PARALLEL

STI_HW_CONFIG_SCSI

STI_HW_CONFIG_SERIAL

STI_HW_CONFIG_USB

STI_HW_CONFIG_UNKNOWN

### `pszVendorDescription`

Pointer to a vendor identification string, obtained from the [INF Manufacturer Section](https://learn.microsoft.com/windows-hardware/drivers/install/inf-manufacturer-section) of the device's INF file.

### `pszDeviceDescription`

Pointer to a vendor-provided device description string, obtained from the [INF Models Section](https://learn.microsoft.com/windows-hardware/drivers/install/inf-models-section) of the device's INF file.

### `pszPortName`

Pointer to a string identifying the device's port.

### `pszPropProvider`

Pointer to a string containing the file name and entry point of a DLL for adding device-specific property sheet pages to Control Panel. Obtained from the **PropertyPages** entry in the device's INF file.

### `pszLocalName`

Pointer to a string containing the local device name (the "friendly" name). The user supplies this string during installation, typically for use in user interface displays.

### `pszUiDll`

Pointer to the WIA user interface DLL.

### `pszServer`

Pointer to the WIA server.