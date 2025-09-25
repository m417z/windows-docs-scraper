# _WINBIO_CAPTURE_DATA structure

## Description

The [IOCTL_BIOMETRIC_CAPTURE_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/winbio_ioctl/ni-winbio_ioctl-ioctl_biometric_capture_data) IOCTL returns the WINBIO_CAPTURE_DATA structure as output.

## Members

### `PayloadSize`

 The total size of the payload. This includes the fixed length structure and any variable data at the end.

### `WinBioHresult`

The status detail of the I/O operation. This is where WINBIO error and information codes will be passed. The following table shows possible values for this member.

|Status value|Description|
|--- |--- |
|S_OK|The operation completed successfully.|
|WINBIO_E_DATA_COLLECTION_IN_PROGRESS|There is already a data collection IOCTL pending.|
|WINBIO_E_UNSUPPORTED_DATA_FORMAT|The format specified is not supported by this driver and device.|
|WINBIO_E_UNSUPPORTED_DATA_TYPE|The type of data requested is not supported by this driver and device.|
|WINBIO_E_INVALID_DEVICE_STATE|The device could not be put into biometric capture mode. This could be because the device is in another non-data collection mode.|
|HRESULT_FROM_NT(STATUS_IO_DEVICE_ERROR)|The operation was not completed due to device error.|
|WINBIO_E_DEVICE_BUSY|The device is in the middle of a vendor-specific operation.|
|WINBIO_E_CANCELED|The operation was canceled either by the caller, or an IOCTL_BIOMETRIC_RESET request.|
|WINBIO_E_UNSUPPORTED_PURPOSE|The capture purpose specified is not supported by the driver.|

### `SensorStatus`

The WINBIO_SENSOR_STATUS status of the sensor after the capture has occurred. It specifies the operating status of the sensor.

WINBIO_SENSOR_STATUS can be queried at any time. When WINBIO_SENSOR_STATUS is returned upon a capture I/O completion, it indicates whether a capture was successful. Possible values are shown in the following table.

|Sensor status code|Description|
|--- |--- |
|WINBIO_SENSOR_ACCEPT|The sensor just successfully completed a capture operation. This should only be returned immediately after a capture operation. The sensor will then return to WINBIO_SENSOR_READY or WINBIO_SENSOR_BUSY.|
|WINBIO_SENSOR_REJECT|The sensor rejected the previous capture operation. This should only be returned immediately following a capture operation. The sensor will then return to WINBIO_SENSOR_READY or WINBIO_SENSOR_BUSY.|
|WINBIO_SENSOR_READY|The sensor is ready to capture data. If there is a pending data capture IOCTL, the sensor is ready to accept data.|
|WINBIO_SENSOR_BUSY|The sensor is busy or in a state where it cannot capture data. For example, the device could still be initializing after it has been turned on.|
|WINBIO_SENSOR_NOT_CALIBRATED|The sensor must be calibrated before it is put into data collection mode.|
|WINBIO_SENSOR_FAILURE|The sensor device failed.|

### `RejectDetail`

If the sensor status was WINBIO_SENSOR_REJECT, this member contains a WINBIO_REJECT_DETAIL value. WINBIO_SENSOR_REJECT specifies the reason a biometric sampling operation failed.

**Important** Values defined for Windows 7 are for fingerprint reject details only.

Failure detail values for WINBIO_TYPE_FINGERPRINT include:

```cpp
#define WINBIO_FP_TOO_HIGH          ((WINBIO_REJECT_DETAIL)1)
#define WINBIO_FP_TOO_LOW           ((WINBIO_REJECT_DETAIL)2)
#define WINBIO_FP_TOO_LEFT          ((WINBIO_REJECT_DETAIL)3)
#define WINBIO_FP_TOO_RIGHT         ((WINBIO_REJECT_DETAIL)4)
#define WINBIO_FP_TOO_FAST          ((WINBIO_REJECT_DETAIL)5)
#define WINBIO_FP_TOO_SLOW          ((WINBIO_REJECT_DETAIL)6)
#define WINBIO_FP_POOR_QUALITY      ((WINBIO_REJECT_DETAIL)7)
#define WINBIO_FP_TOO_SKEWED        ((WINBIO_REJECT_DETAIL)8)
#define WINBIO_FP_TOO_SHORT         ((WINBIO_REJECT_DETAIL)9)
#define WINBIO_FP_MERGE_FAILURE     ((WINBIO_REJECT_DETAIL)10)
```

### `CaptureData`

A structure of type [WINBIO_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/winbio_ioctl/ns-winbio_ioctl-_winbio_data) that contains data captured by the device, of the format specified. The **Data** array member of the WINBIO_DATA structure should contain a [WINBIO_BIR](https://learn.microsoft.com/windows-hardware/drivers/ddi/winbio_types/ns-winbio_types-_winbio_bir) structure.

## See also

[IOCTL_BIOMETRIC_CAPTURE_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/winbio_ioctl/ni-winbio_ioctl-ioctl_biometric_capture_data)