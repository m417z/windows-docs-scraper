# _WINBIO_CALIBRATION_INFO structure

## Description

The [IOCTL_BIOMETRIC_CALIBRATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/winbio_ioctl/ni-winbio_ioctl-ioctl_biometric_calibrate) IOCTL returns the WINBIO_CALIBRATION_INFO structure as output.

## Members

### `PayloadSize`

The total size of the payload. This includes the fixed length structure and any variable data at the end.

### `WinBioHresult`

The status detail of the I/O operation. This is where WINBIO error and information codes will be passed. The following table shows possible values for this member.

|Status value|Description|
|--- |--- |
|S_OK|The operation completed successfully.|
|HRESULT_FROM_NT(STATUS_IO_DEVICE_ERROR)|The driver could not gather the necessary information from the device.|
|WINBIO_E_DEVICE_BUSY|The device is in the middle of a vendor-specific operation. This should only be returned when the device cannot be reset, and the vendor-specific operation cannot be canceled.|

### `CalibrationData`

A structure of type [WINBIO_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/winbio_ioctl/ns-winbio_ioctl-_winbio_data) that contains calibration data specific to this sensor. This member is optional.