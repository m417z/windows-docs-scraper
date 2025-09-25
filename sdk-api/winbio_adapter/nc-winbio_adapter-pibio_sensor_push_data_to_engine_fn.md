# PIBIO_SENSOR_PUSH_DATA_TO_ENGINE_FN callback function

## Description

Called by the Windows Biometric Framework to make the current contents of the sample buffer available to the engine adapter.

## Parameters

### `Pipeline` [in, out]

Pointer to the [WINBIO_PIPELINE](https://learn.microsoft.com/windows/desktop/api/winbio_adapter/ns-winbio_adapter-winbio_pipeline) structure associated with the biometric unit performing the operation.

### `Purpose` [in]

A value that specifies the properties of the [WINBIO_BIR](https://learn.microsoft.com/windows/desktop/SecBioMet/winbio-bir) structure that will be passed to the engine. This can be a bitwise **OR** of the following security and processing level flags:

* WINBIO_PURPOSE_VERIFY
* WINBIO_PURPOSE_IDENTIFY
* WINBIO_PURPOSE_ENROLL
* WINBIO_PURPOSE_ENROLL_FOR_VERIFICATION
* WINBIO_PURPOSE_ENROLL_FOR_IDENTIFICATION

### `Flags` [in]

A value that specifies the format of the sample. This can be a bitwise **OR** of the following security and processing level flags:

* **WINBIO_DATA_FLAG_PRIVACY**

The sample should be encrypted.
* **WINBIO_DATA_FLAG_INTEGRITY**

The sample should be digitally signed or protected by a message authentication code (MAC).
* **WINBIO_DATA_FLAG_SIGNED**

If this flag and the WINBIO_DATA_FLAG_INTEGRITY flag are set, the sample should be signed. If this flag is not set but the WINBIO_DATA_FLAG_INTEGRITY flag is set, a MAC should be computed.
* **WINBIO_DATA_FLAG_RAW**

The sample should be placed in the WINBIO_BIR object in the format in which it was captured.

### `RejectDetail` [out]

A pointer to a **WINBIO_REJECT_DETAIL** value that contains information about the previous failure to capture a biometric sample and therefore the reason that the sample buffer is empty. If an earlier capture succeeded, this parameter is set to zero. The following values are defined for fingerprint capture:

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

If the function succeeds, it returns S_OK. If the function fails, it must return one of the following **HRESULT** values to indicate the error.

| Return code | Description |
| --- | --- |
| **E_POINTER** | A mandatory pointer argument is **NULL**. |
| **WINBIO_E_BAD_CAPTURE** | The sample data is not suitable for use. If you return this error code, you must also specify a value in the *RejectDetail* parameter to indicate the nature of the problem. |
| **WINBIO_E_INVALID_DEVICE_STATE** | The **SensorContext** member of the [WINBIO_PIPELINE](https://learn.microsoft.com/windows/desktop/api/winbio_adapter/ns-winbio_adapter-winbio_pipeline) structure pointed to by the *Pipeline* argument is **NULL**. |
| **WINBIO_E_NO_CAPTURE_DATA** | No capture data exists. |

## Remarks

Your implementation of this function should convert raw data contained in the sample buffer into a standard [WINBIO_BIR](https://learn.microsoft.com/windows/desktop/SecBioMet/winbio-bir) structure and push this structure to the engine by using the [EngineAdapterAcceptSampleData](https://learn.microsoft.com/windows/desktop/api/winbio_adapter/nc-winbio_adapter-pibio_engine_accept_sample_data_fn) function. The correct way to do this is to call the **WbioEngineAcceptSampleData** helper function defined in Winbio_adapter.h header file.

If the [EngineAdapterAcceptSampleData](https://learn.microsoft.com/windows/desktop/api/winbio_adapter/nc-winbio_adapter-pibio_engine_accept_sample_data_fn) function returns WINBIO_E_BAD_CAPTURE, your implementation of *SensorAdapterPushDataToEngine* should return the *RejectDetail* value propagated by the engine adapter.

The sensor adapter retains ownership of the sample buffer passed to [EngineAdapterAcceptSampleData](https://learn.microsoft.com/windows/desktop/api/winbio_adapter/nc-winbio_adapter-pibio_engine_accept_sample_data_fn). The sensor adapter is responsible for releasing this buffer at some point after *EngineAdapterAcceptSampleData* returns.

#### Examples

The following pseudocode shows one possible implementation of this function. The example does not compile. You must adapt it to suit your purpose.

```cpp
//////////////////////////////////////////////////////////////////////////////////////////
//
// SensorAdapterPushDataToEngine
//
// Purpose:
//      Makes the current contents of the sample buffer available to the
//      engine adapter.
//
// Parameters:
//      Pipeline     -  Pointer to a WINBIO_PIPELINE structure associated with
//                      the biometric unit.
//      Purpose      -  Specifies the properties of the WINBIO_BIR structure
//                      that will be passed to the engine.
//      Flags        -  A value that specifies the format of the sample.
//      RejectDetail -  Pointer to a WINBIO_REJECT_DETAIL value that receives
//                      additional information about the reason the sample
//                      buffer is empty.
//
static HRESULT
WINAPI
SensorAdapterPushDataToEngine(
    __inout PWINBIO_PIPELINE Pipeline,
    __in WINBIO_BIR_PURPOSE Purpose,
    __in WINBIO_BIR_DATA_FLAGS Flags,
    __out PWINBIO_REJECT_DETAIL RejectDetail
    )
{
    HRESULT hr = S_OK;

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
    if (sensorContext == NULL)
    {
        hr = WINBIO_E_INVALID_DEVICE_STATE;
        goto cleanup;
    }

    if (sensorContext->CaptureBuffer != NULL &&
        sensorContext->CaptureBufferSize >= sizeof (WINBIO_CAPTURE_DATA) &&
        sensorContext->CaptureBuffer->CaptureData.Size != 0 &&
        sensorContext->CaptureBuffer->SensorStatus == WINBIO_SENSOR_ACCEPT)
    {
        // There is valid capture data in the Pipeline. Call the
        // WbioEngineAcceptSampleData function to notify the engine adapter, but
        // retain ownership of the buffer in the sensor adapter.
        // WbioEngineAcceptSampleData is a wrapper function declared in the
        // Winbio_adapter.h header file.
        hr = WbioEngineAcceptSampleData(
                    Pipeline,
                    (PWINBIO_BIR)sensorContext->CaptureBuffer->CaptureData.Data,
                    sensorContext->CaptureBuffer->CaptureData.Size,
                    Purpose,
                    RejectDetail
                    );
    }
    else if (sensorContext->CaptureBuffer != NULL &&
             sensorContext->CaptureBufferSize >= sizeof (WINBIO_CAPTURE_DATA) &&
             sensorContext->CaptureBuffer->WinBioHresult == WINBIO_E_BAD_CAPTURE)
    {
        // The most recent capture was not acceptable.  Do not attempt to push
        // the sample to the engine. Instead, simply return the reject detail
        // information generated by the previous capture.
        hr = sensorContext->CaptureBuffer->WinBioHresult;
        *RejectDetail = sensorContext->CaptureBuffer->RejectDetail;
    }
    else
    {
        hr = WINBIO_E_NO_CAPTURE_DATA;
    }

    return hr;
}

```

## See also

[Plug-in Functions](https://learn.microsoft.com/windows/desktop/SecBioMet/plug-in-functions)