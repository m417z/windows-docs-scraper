# PIBIO_SENSOR_SET_CALIBRATION_FORMAT_FN callback function

## Description

Called by the Windows Biometric Framework to notify the sensor adapter that a particular calibration data format has been selected by the engine adapter.

## Parameters

### `Pipeline` [in, out]

Pointer to the [WINBIO_PIPELINE](https://learn.microsoft.com/windows/desktop/api/winbio_adapter/ns-winbio_adapter-winbio_pipeline) structure associated with the biometric unit performing the operation.

### `Format` [in]

Address of a [WINBIO_UUID](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/winbio_ioctl/ns-winbio_ioctl-_winbio_capture_parameters) identifying the calibration data format selected by the Engine Adapter.

## Return value

The function will return one of the following **HRESULT** values.

| Return code | Description |
| --- | --- |
| **S_OK** | The operation succeeded. |
| **E_NOTIMPL** | The Sensor Adapter doesn’t support dynamic calibration. This is only treated as an error if the [SensorAdapterQueryCalibrationFormats](https://learn.microsoft.com/windows/desktop/api/winbio_adapter/nc-winbio_adapter-pibio_sensor_query_calibration_formats_fn) method has previously indicated that the adapter supports dynamic calibration. |
| **WINBIO_E_UNSUPPORTED_SENSOR_CALIBRATION_FORMAT** | The UUID specified in the *Format* parameter is not one of the ones supported by the Sensor Adapter. This error code will cause the Biometric Service to log the error and abort the configuration of the biometric unit. |
| **E_some_other_error** | Any other error code will cause the Biometric Service to log the error and abort the configuration of the biometric unit. |

## Remarks

The Sensor Adapter should store a copy of this UUID value for later use in interpreting the contents of any calibration buffers sent to its [SensorAdapterAcceptCalibrationData](https://learn.microsoft.com/windows/desktop/api/winbio_adapter/nc-winbio_adapter-pibio_sensor_accept_calibration_data_fn) method.