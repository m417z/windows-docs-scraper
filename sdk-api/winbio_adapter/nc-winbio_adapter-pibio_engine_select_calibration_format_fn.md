# PIBIO_ENGINE_SELECT_CALIBRATION_FORMAT_FN callback function

## Description

Called by the Windows Biometric Framework to determine which of the Sensor Adapter’s calibration formats the Engine Adapter wants to use.

## Parameters

### `Pipeline` [in, out]

Pointer to the [WINBIO_PIPELINE](https://learn.microsoft.com/windows/desktop/api/winbio_adapter/ns-winbio_adapter-winbio_pipeline) structure associated with the biometric unit performing the operation.

### `FormatArray` [in]

Address of an array of [WINBIO_UUID](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/winbio_ioctl/ns-winbio_ioctl-_winbio_capture_parameters) items identifying the calibration data formats supported by the Sensor Adapter. The Engine Adapter is expected to choose one of these formats for its calibration data.

### `FormatCount` [in]

Value indicating the number of UUIDs in the *FormatArray* parameter.

### `SelectedFormat` [out]

Address of a [WINBIO_UUID](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/winbio_ioctl/ns-winbio_ioctl-_winbio_capture_parameters) item where the **EngineAdapterSelectCalibrationFormat** method will store the UUID of the selected calibration format. This must be one of the UUIDs in the *FormatArray* parameter.

### `MaxBufferSize` [out]

Address of a variable where the **EngineAdapterSelectCalibrationFormat** method will store the maximum size (in bytes) of any calibration data it plans to return to the Sensor Adapter. The maximum size of this buffer must be 4096 bytes or less.

## Return value

The function will return one of the following **HRESULT** values.

| Return code | Description |
| --- | --- |
| **S_OK** | The operation succeeded. The *SelectedFormat* and *MaxBufferSize* return values have both been set. |
| **E_NOTIMPL** | The Engine Adapter doesn’t require dynamic calibration. This is not an error condition. The Biometric Service will convert this value to **S_OK**, and the biometric unit will be configured not to use dynamic calibration. |
| **WINBIO_E_NO_SUPPORTED_CALIBRATION_FORMAT** | The Engine Adapter requires dynamic calibration, but doesn’t support any of the calibration formats specified in the *FormatArray* parameter. (The Engine Adapter should also return this error code if the *FormatCount* argument is zero.) This error code will cause the Biometric Service to log the error and abort the configuration of the biometric unit. |
| **E_some_other_error** | Any other error code will cause the Biometric Service to log the error and abort the configuration of the biometric unit. |

## Remarks

This method is called once during configuration of the biometric unit. After a calibration format has been selected, it cannot be changed.