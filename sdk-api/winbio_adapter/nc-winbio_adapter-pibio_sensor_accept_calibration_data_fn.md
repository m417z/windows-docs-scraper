# PIBIO_SENSOR_ACCEPT_CALIBRATION_DATA_FN callback function

## Description

Called by the Windows Biometric Framework to pass calibration data from the engine adapter to the sensor adapter.

## Parameters

### `Pipeline` [in, out]

Pointer to the [WINBIO_PIPELINE](https://learn.microsoft.com/windows/desktop/api/winbio_adapter/ns-winbio_adapter-winbio_pipeline) structure associated with the biometric unit performing the operation.

### `CalibrationBuffer` [in]

Pointer to the buffer that contains the calibration data.

### `CalibrationBufferSize` [in]

The size in bytes of the calibration buffer.

## Return value

If the function succeeds, it returns **S_OK**. If the function fails, it must return one of the following **HRESULT** values to indicate the error.

| Return code | Description |
| --- | --- |
| **E_some_error** | Any error code will cause the Biometric Service to discontinue the dynamic calibration loop and abort the capture operation. |

## Remarks

This method is called during a dynamic calibration loop.

The memory holding the calibration buffer belongs to the Windows Biometric Framework, and the Sensor Adapter must not keep any pointers to this buffer once the **SensorAdapterAcceptCalibrationData** method returns.