# _WINBIO_DIAGNOSTICS structure

## Description

The [IOCTL_BIOMETRIC_GET_SENSOR_STATUS](https://learn.microsoft.com/windows-hardware/drivers/ddi/winbio_ioctl/ni-winbio_ioctl-ioctl_biometric_get_sensor_status) IOCTL returns the WINBIO_DIAGNOSTICS structure as output.

## Members

### `PayloadSize`

The total size of the payload. This includes the fixed length structure and any variable data at the end.

### `WinBioHresult`

The status detail of the I/O operation. This is where WINBIO error and information codes will be passed. The following table shows possible values.

|Status value|Description|
|--- |--- |
|S_OK|The operation completed successfully.|
|HRESULT_FROM_NT(STATUS_IO_DEVICE_ERROR)|The driver could not gather the necessary information from the device.|

### `SensorStatus`

A structure of type [WINBIO_SENSOR_STATUS](https://learn.microsoft.com/windows-hardware/drivers/ddi/winbio_ioctl/ns-winbio_ioctl-_winbio_capture_data) that contains the operating status of the biometric sensor.

### `VendorDiagnostics`

An optional [WINBIO_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/winbio_ioctl/ns-winbio_ioctl-_winbio_data) structure for vendor-specific additional information.

## See also

[IOCTL_BIOMETRIC_GET_SENSOR_STATUS](https://learn.microsoft.com/windows-hardware/drivers/ddi/winbio_ioctl/ni-winbio_ioctl-ioctl_biometric_get_sensor_status)