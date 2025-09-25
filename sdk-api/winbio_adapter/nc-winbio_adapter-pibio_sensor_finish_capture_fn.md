# PIBIO_SENSOR_FINISH_CAPTURE_FN callback function

## Description

Called by the Windows Biometric Framework to wait for the completion of a capture operation initiated by the [SensorAdapterStartCapture](https://learn.microsoft.com/windows/desktop/api/winbio_adapter/nc-winbio_adapter-pibio_sensor_start_capture_fn) function.

## Parameters

### `Pipeline` [in, out]

Pointer to a [WINBIO_PIPELINE](https://learn.microsoft.com/windows/desktop/api/winbio_adapter/ns-winbio_adapter-winbio_pipeline) structure associated with the biometric unit performing the operation.

### `RejectDetail` [out]

Pointer to a **WINBIO_REJECT_DETAIL** value that receives additional information about the failure to capture a biometric sample. If the operation succeeded, this parameter is set to zero. The following values are defined for fingerprint samples:

* WINBIO_FP_TOO_HIGH
* WINBIO_FP_TOO_LOW
* WINBIO_FP_TOO_LEFT
* WINBIO_FP_TOO_RIGHT
* WINBIO_FP_TOO_FAST
* WINBIO_FP_TOO_SLOW
* WINBIO_FP_POOR_QUALITY
* WINBIO_FP_TOO_SKEWED
* WINBIO_FP_TOO_SHORT
* WINBIO_FP_MERGE_FAILURE

## Return value

If the function succeeds, it returns S_OK. If the function fails, it returns an **HRESULT** value that indicates the error. The following values will be recognized by the Windows Biometric Framework.

| Return code | Description |
| --- | --- |
| ****WINBIO_E_BAD_CAPTURE**** | The sample could not be captured. If you return this error code, you must also specify a value in the *RejectDetail* parameter that indicates the nature of the problem. |
| ****WINBIO_E_CAPTURE_CANCELED**** | The sensor driver returned **ERROR_CANCELLED** or **ERROR_OPERATION_ABORTED**. |
| **WINBIO_E_DEVICE_FAILURE** | There was a device failure. |
| **WINBIO_E_INVALID_DEVICE_STATE** | The **SensorContext** member of the [WINBIO_PIPELINE](https://learn.microsoft.com/windows/desktop/api/winbio_adapter/ns-winbio_adapter-winbio_pipeline) structure pointed to by the *Pipeline* argument is **NULL** or the **SensorHandle** member is set to **INVALID_HANDLE_VALUE**. |

## Remarks

The Windows Biometric Framework calls this function after it successfully calls [SensorAdapterStartCapture](https://learn.microsoft.com/windows/desktop/api/winbio_adapter/nc-winbio_adapter-pibio_sensor_start_capture_fn) or it calls [SensorAdapterCancel](https://learn.microsoft.com/windows/desktop/api/winbio_adapter/nc-winbio_adapter-pibio_sensor_cancel_fn). It does not call this function if the call to *SensorAdapterStartCapture* fails.

When your implementation of this function returns, the data in the pipeline should be ready for subsequent calls to functions such as [SensorAdapterPushDataToEngine](https://learn.microsoft.com/windows/desktop/api/winbio_adapter/nc-winbio_adapter-pibio_sensor_push_data_to_engine_fn) or [SensorAdapterExportSensorData](https://learn.microsoft.com/windows/desktop/api/winbio_adapter/nc-winbio_adapter-pibio_sensor_export_sensor_data_fn).

This is a blocking function that should return only after the sensor I/O operation has succeeded, failed, or been canceled. Typically, you will make this function block by passing the **OVERLAPPED** structure in the sensor adapter context to the [GetOverlappedResult](https://learn.microsoft.com/windows/desktop/api/ioapiset/nf-ioapiset-getoverlappedresult) function. The **hEvent** handle in the **OVERLAPPED** structure must be signaled when *SensorAdapterFinishCapture* returns. The *GetOverlappedResult* function sets this handle automatically when it detects the end of a sensor I/O operation. If your adapter uses some other mechanism to detect I/O completion, you must signal the event yourself.

#### Examples

The following pseudocode shows one possible implementation of this function. The example does not compile. You must adapt it to suit your purpose.

```cpp
//////////////////////////////////////////////////////////////////////////////////////////
//
// SensorAdapterFinishCapture
//
// Purpose:
//      Waits for the completion of a capture operation initiated by the
//      SensorAdapterStartCapture function.
//
// Parameters:
//      Pipeline     -  Pointer to a WINBIO_PIPELINE structure associated with
//                      the biometric unit.
//      RejectDetail -  Pointer to a WINBIO_REJECT_DETAIL value that receives
//                      additional information about the failure to capture a
//                      biometric sample.
//
static HRESULT
WINAPI
SensorAdapterFinishCapture(
    __inout PWINBIO_PIPELINE Pipeline,
    __out PWINBIO_REJECT_DETAIL RejectDetail
    )
{
    HRESULT hr = S_OK;
    WINBIO_SENSOR_STATUS sensorStatus = WINBIO_SENSOR_FAILURE;
    WINBIO_CAPTURE_PARAMETERS captureParameters = {0};
    BOOL result = TRUE;
    DWORD bytesReturned = 0;

    // Verify that pointer arguments are not NULL.
    if (!ARGUMENT_PRESENT(Pipeline) ||
        !ARGUMENT_PRESENT(RejectDetail))
    {
        hr = E_POINTER;
        goto cleanup;
    }

    // Retrieve the context from the pipeline.
    PWINBIO_SENSOR_CONTEXT sensorContext =
             (PWINBIO_SENSOR_CONTEXT)Pipeline->SensorContext;

    // Verify the state of the pipeline.
    if (sensorContext == NULL ||
        Pipeline->SensorHandle == INVALID_HANDLE_VALUE)
    {
        return WINBIO_E_INVALID_DEVICE_STATE;
    }

    // Initialize the RejectDetail argument.
    *RejectDetail = 0;

    // Wait for I/O completion. This sample assumes that the I/O operation was
    // started using the code example shown in the SensorAdapterStartCapture
    // documentation.
    SetLastError(ERROR_SUCCESS);

    result = GetOverlappedResult(
                Pipeline->SensorHandle,
                &sensorContext->Overlapped,
                &bytesReturned,
                TRUE
                );
    if (!result)
    {
        // There was an I/O error.
        return _AdapterGetHresultFromWin32(GetLastError());
    }

    if (bytesReturned == sizeof (DWORD))
    {
        // The buffer is not large enough.  This can happen if a device needs a
        // bigger buffer depending on the purpose. Allocate a larger buffer and
        // force the caller to reissue their I/O request.
        DWORD allocationSize = sensorContext->CaptureBuffer->PayloadSize;

        // Allocate at least the minimum buffer size needed to retrieve the
        // payload structure.
        if (allocationSize < sizeof(WINBIO_CAPTURE_DATA))
        {
            allocationSize = sizeof(WINBIO_CAPTURE_DATA);
        }

        // Free the old buffer and allocate a new one.
        _AdapterRelease(sensorContext->CaptureBuffer);
        sensorContext->CaptureBuffer = NULL;

        sensorContext->CaptureBuffer =
            (PWINBIO_CAPTURE_DATA)_AdapterAlloc(allocationSize);
        if (sensorContext->CaptureBuffer == NULL)
        {
            sensorContext->CaptureBufferSize = 0;
            return E_OUTOFMEMORY;
        }
        sensorContext->CaptureBufferSize = allocationSize;
        return WINBIO_E_BAD_CAPTURE;
    }

    // Normalize the status value before sending it back to the biometric service.
    if (sensorContext->CaptureBuffer != NULL &&
        sensorContext->CaptureBufferSize >= sizeof (WINBIO_CAPTURE_DATA))
    {
        switch (sensorContext->CaptureBuffer->SensorStatus)
        {
            case WINBIO_SENSOR_ACCEPT:
                // The capture was acceptable.
                break;

            case WINBIO_SENSOR_REJECT:
                // The capture was not acceptable. Overwrite the WinBioHresult value
                // in case it has not been properly set.
                sensorContext->CaptureBuffer->WinBioHresult = WINBIO_E_BAD_CAPTURE;
                break;

            case WINBIO_SENSOR_BUSY:
                // The device is busy. Reset the WinBioHresult value in case it
                // has not been properly set.
                sensorContext->CaptureBuffer->WinBioHresult = WINBIO_E_DEVICE_BUSY;
                break;

            case WINBIO_SENSOR_READY:
            case WINBIO_SENSOR_NOT_CALIBRATED:
            case WINBIO_SENSOR_FAILURE:
            default:
                // There has been a device failure. Reset the WinBioHresult value
                // in case it has not been properly set.
                sensorContext->CaptureBuffer->WinBioHresult = WINBIO_E_INVALID_DEVICE_STATE;
                break;
        }

        *RejectDetail = sensorContext->CaptureBuffer->RejectDetail;
        hr = sensorContext->CaptureBuffer->WinBioHresult;
    }
    else
    {
        // The buffer is not large enough or the buffer pointer is NULL.
        hr = WINBIO_E_INVALID_DEVICE_STATE;
    }
    return hr;
}

```

## See also

[Plug-in Functions](https://learn.microsoft.com/windows/desktop/SecBioMet/plug-in-functions)

[SensorAdapterCancel](https://learn.microsoft.com/windows/desktop/api/winbio_adapter/nc-winbio_adapter-pibio_sensor_cancel_fn)

[SensorAdapterExportSensorData](https://learn.microsoft.com/windows/desktop/api/winbio_adapter/nc-winbio_adapter-pibio_sensor_export_sensor_data_fn)

[SensorAdapterPushDataToEngine](https://learn.microsoft.com/windows/desktop/api/winbio_adapter/nc-winbio_adapter-pibio_sensor_push_data_to_engine_fn)

[SensorAdapterStartCapture](https://learn.microsoft.com/windows/desktop/api/winbio_adapter/nc-winbio_adapter-pibio_sensor_start_capture_fn)