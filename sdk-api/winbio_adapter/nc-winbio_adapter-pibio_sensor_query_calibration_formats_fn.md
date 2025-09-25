# PIBIO_SENSOR_QUERY_CALIBRATION_FORMATS_FN callback function

## Description

Called by the Windows Biometric Framework to determine the set of calibration formats supported by the Sensor Adapter.

## Parameters

### `Pipeline` [in, out]

Pointer to the [WINBIO_PIPELINE](https://learn.microsoft.com/windows/desktop/api/winbio_adapter/ns-winbio_adapter-winbio_pipeline) structure associated with the biometric unit performing the operation.

### `FormatArray` [out]

Address of an array of empty [WINBIO_UUID](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/winbio_ioctl/ns-winbio_ioctl-_winbio_capture_parameters) items. The **SensorAdapterQueryCalibrationFormats** method is expected to fill this array with one or more UUIDs identifying the calibration data formats known to the Sensor Adapter.

### `FormatArraySize` [in]

A value indicating the number of slots available in *FormatArray*. The **SensorAdapterQueryCalibrationFormats** method must not attempt to write more than this number of elements into *FormatArray*, or the results will be unpredictable.

### `FormatCount` [out]

Pointer to a variable that receives the number UUIDs returned in *FormatArray*. The **SensorAdapterQueryCalibrationFormats** method must set this value before returning.

## Return value

If the function succeeds, it returns **S_OK**. If the function fails, it must return one of the following **HRESULT** values to indicate the error.

| Return code | Description |
| --- | --- |
| **E_NOTIMPL** | – The Sensor Adapter doesn’t support dynamic calibration. |
| **E_some_other_error** | Any other error code will cause the Windows Biometric Framework to log the error and abort the configuration of the biometric unit. |

## Remarks

This method is called once during the initial configuration of a biometric unit.

Each calibration format supported by the Sensor Adapter is identified by a separate UUID value.

This method executes in the context of an arbitrary RPC server thread.

If the Sensor Adapter doesn’t support dynamic calibration, it should return a value of **E_NOTIMPL**. The Windows Biometric Framework will not treat this as an error unless the Engine Adapter requires dynamic calibration. (For details, see the description of the [EngineAdapterSelectCalibrationFormat](https://learn.microsoft.com/windows/desktop/api/winbio_adapter/nc-winbio_adapter-pibio_engine_select_calibration_format_fn) method.)

If this method returns a value of **S_OK**, *FormatArray* and *FormatCount* must be set. It is an error for this method to return **S_OK** along with a zero value for *FormatCount*. Doing so will cause the Windows Biometric Framework to log a **WINBIO_E_INVALID_CALIBRATION_FORMAT_ARRAY** error message and abort the configuration of the biometric unit.