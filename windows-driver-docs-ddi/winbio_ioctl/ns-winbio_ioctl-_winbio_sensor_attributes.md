# _WINBIO_SENSOR_ATTRIBUTES structure

## Description

The [IOCTL_BIOMETRIC_GET_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/winbio_ioctl/ni-winbio_ioctl-ioctl_biometric_get_attributes) structure returns the WINBIO_SENSOR_ATTRIBUTES structure as output.

## Members

### `PayloadSize`

A DWORD value that indicates the total size of the payload, including the fixed length structure and any variable data at the end.

### `WinBioHresult`

An HRESULT value that indicates containing status detail of the I/O operation. The following table includes possible values.

|Status value|Description|
|--- |--- |
|S_OK|The operation completed successfully.|
|HRESULT_FROM_NT(STATUS_IO_DEVICE_ERROR)|The driver could not gather the necessary information from the device.|

### `WinBioVersion`

A structure of type [WINBIO_VERSION](https://learn.microsoft.com/windows-hardware/drivers/ddi/winbio_types/ns-winbio_types-_winbio_version) that contains a WinBio WBDI version that is supported by the driver. To be compatible with the WinBio service, **WinBioVersion** must contain the same major version as the current major version of the WinBio service, in addition to a minor version that is less than or equal to the current minor version of the WinBio service.

### `SensorType`

A DWORD bitmask of type WINBIO_BIOMETRIC_TYPE that contains biometric data that is collected by the sensor. In Windows 7, only WINBIO_TYPE_FINGERPRINT is supported.

### `SensorSubType`

A WINBIO_BIOMETRIC_SENSOR_SUBTYPE subtype that contains additional information about the sensor. For example, this member could specify whether the sensor requires the user to simply touch the sensor or swipe a finger over the sensor.

WINBIO_BIOMETRIC_SENSOR_SUBTYPE can contain the values in the following table.

|Biometric subtype value|Description|
|--- |--- |
|WINBIO_FP_SENSOR_SUBTYPE_SWIPE|The device requires the user to swipe their fingertip over the sensor.|
|WINBIO_FP_SENSOR_SUBTYPE_TOUCH|The device requires the user to place their entire fingerprint on a sensor pad.|

### `Capabilities`

A WINBIO_CAPABILITIES subtype, which indicates which capabilities are supported by the device.

WINBIO_CAPABILITIES can contain the values in the following table.

|Biometric capability value|Description|
|--- |--- |
|WINBIO_CAPABILITY_SENSOR|The device can collect biometric data.|
|WINBIO_CAPABILITY_MATCHING|The device can perform match operations.|
|WINBIO_CAPABILITY_STORAGE|The device can store biometric templates.|
|WINBIO_CAPABILITY_SECURE_STORAGE|The device can store secure data that is associated with a template. The secure data is only released with a positive match. The device must support at least the SHA-1 algorithm for secure hash computation to be used to store templates in the system pool.|
|WINBIO_CAPABILITY_PROCESSING|The device can process samples and turn them into biometric templates.|
|WINBIO_CAPABILITY_ENCRYPTION|The device supports encryption of samples and templates.|
|WINBIO_CAPABILITY_SIGNING|The device can sign captured data.|
|WINBIO_CAPABILITY_NAVIGATION|The device can be used as a navigation device. Some devices and drivers can capture data in a format that can be translated by a user-mode application into navigation events, much like a mouse.|
|WINBIO_CAPABILITY_INDICATOR|The device has an indicator that can be turned on or off.|
|WINBIO_CAPABILITY_VIRTUAL_SENSOR|The sensor adapter manages its own connection to the biometric hardware. **Note:** This constant applies only for Windows 10 and later.|
|WINBIO_CAPABILITY_SECURE_SENSOR|The device supports security methods available in the WinBio engine adapter interface version 4.0 or later. **Note:** This constant applies only for Windows 10 and later.|

### `ManufacturerName`

 A structure of type WINBIO_STRING that contains the name of the device manufacturer.

### `ModelName`

 A structure of type WINBIO_STRING that contains the name of the device model.

### `SerialNumber`

A structure of type WINBIO_STRING that contains the serial number of the device, if one exists.

### `FirmwareVersion`

 A structure of type [WINBIO_VERSION](https://learn.microsoft.com/windows-hardware/drivers/ddi/winbio_types/ns-winbio_types-_winbio_version) that contains the version of the firmware that is loaded on the device.

### `SupportedFormatEntries`

 The number of formats that are supported by the driver and device. There must be at least one, which is the Windows standard format.

### `SupportedFormat`

A structure of type [WINBIO_REGISTERED_FORMAT](https://learn.microsoft.com/windows-hardware/drivers/ddi/winbio_types/ns-winbio_types-_winbio_registered_format) that contains a list of the formats supported by the driver and device.

## See also

[IOCTL_BIOMETRIC_GET_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/winbio_ioctl/ni-winbio_ioctl-ioctl_biometric_get_attributes)