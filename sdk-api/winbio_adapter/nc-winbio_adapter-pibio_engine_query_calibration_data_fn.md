# PIBIO_ENGINE_QUERY_CALIBRATION_DATA_FN callback function

## Description

Called by the Windows Biometric Framework to get a set of post-capture calibration data from the engine adapter.

## Parameters

### `Pipeline` [in, out]

Pointer to the [WINBIO_PIPELINE](https://learn.microsoft.com/windows/desktop/api/winbio_adapter/ns-winbio_adapter-winbio_pipeline) structure associated with the biometric unit performing the operation.

### `DiscardAndRepeatCapture` [out]

Address of a Boolean value that must be set by the **EngineAdapterQueryCalibrationData** method. This value indicates what the biometric service should do with the current sample after calibration is complete.

* **TRUE** indicates that the captured biometric sample is unusable. The biometric service will discard the sample and collect a new one.
* **FALSE** indicates that the sample is usable and the Engine should be instructed to perform further operations on it.

### `CalibrationBuffer` [out]

Address of an empty buffer where the method is expected to write its calibration data. The memory holding this buffer belongs to the biometric service, and the Engine Adapter must not keep any pointers to this buffer once the **EngineAdapterQueryCalibrationData** method returns.

### `CalibrationBufferSize` [out]

Address of a variable where the **EngineAdapterQueryCalibrationData** method will store the size (in bytes) of the calibration data it has written to *CalibrationBuffer*. This value must not exceed *MaxBufferSize*.

If **EngineAdapterQueryCalibrationData** sets this value to zero, the contents of the *CalibrationBuffer* will be discarded without sending them to the Sensor Adapter. This is not an error condition; it simply indicates that the Engine Adapter doesn’t need to update the sensor’s calibration based on the current capture data.

### `MaxBufferSize` [in]

A value indicating the maximum space (in bytes) available to the Engine Adapter in the *CalibrationBuffer*.

## Return value

If the function succeeds, it returns **S_OK**. If the function fails, it must return one of the following **HRESULT** values to indicate the error.

| Return code | Description |
| --- | --- |
| **E_some_error** | Any error code will cause the Biometric Service to discontinue the dynamic calibration loop and abort the capture operation. |

## Remarks

The **EngineAdapterQueryCalibrationData** method can independently control the biometric service’s repeat-capture behavior and the calibration behavior by setting *DiscardAndRepeatCapture* and *CalibrationBufferSize*, respectively.

| Desired Behavior | *DiscardAndRepeatCapture* | *CalibrationBufferSize* |
| --- | --- | --- |
| Repeat capture after calibration. | **TRUE** | Non-zero |
| Repeat capture without calibration. | **TRUE** | Zero |
| Continue processing the sample after calibration. | **FALSE** | Non-zero |
| Continue processing the sample without calibration. | **FALSE** | Zero |