# PIBIO_ENGINE_ACCEPT_SAMPLE_DATA_FN callback function

## Description

Called by the [SensorAdapterPushDataToEngine](https://learn.microsoft.com/windows/desktop/api/winbio_adapter/nc-winbio_adapter-pibio_sensor_push_data_to_engine_fn) function implemented by the sensor adapter to notify the engine adapter to accept a raw biometric sample and extract a feature set. The feature set can be used for matching or enrollment.

## Parameters

### `Pipeline` [in, out]

Pointer to a [WINBIO_PIPELINE](https://learn.microsoft.com/windows/desktop/api/winbio_adapter/ns-winbio_adapter-winbio_pipeline) structure associated with the biometric unit performing the operation.

### `SampleBuffer` [in]

Pointer to a [WINBIO_BIR](https://learn.microsoft.com/windows/desktop/SecBioMet/winbio-bir) structure that contains the biometric sample to be processed.

### `SampleSize` [in]

A **SIZE_T** value that contains the size of the [WINBIO_BIR](https://learn.microsoft.com/windows/desktop/SecBioMet/winbio-bir) structure returned in the *SampleBuffer* parameter.

### `Purpose` [in]

A **WINBIO_BIR_PURPOSE** bitmask that specifies the intended use of the sample. The **WINBIO_BIR_PURPOSE** structure specifies the purpose for which capture data is to be used, and (as a result) how it should be optimized. This can be a bitwise **OR** of the following values:

* WINBIO_PURPOSE_VERIFY
* WINBIO_PURPOSE_IDENTIFY
* WINBIO_PURPOSE_ENROLL
* WINBIO_PURPOSE_ENROLL_FOR_VERIFICATION
* WINBIO_PURPOSE_ENROLL_FOR_IDENTIFICATION

### `RejectDetail` [out]

A pointer to a **WINBIO_REJECT_DETAIL** value that receives additional information about the failure to process a biometric sample. If the operation succeeded, this parameter is set to zero. The following values are defined for fingerprint samples:

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
| **E_INVALIDARG** | The *SampleSize* argument cannot be zero. The *Purpose* argument must be a bitwise **OR** of the values listed in the parameter description. |
| **E_POINTER** | The *Pipeline*, *SampleBuffer*, and *RejectDetail* arguments cannot be **NULL**. |
| **E_OUTOFMEMORY** | The operation could not be completed because of insufficient memory. |
| **WINBIO_E_BAD_CAPTURE** | The data could not be processed to create the required feature set. The RejectDetail contains additional information about the failure. |

## Remarks

The feature set created by calling this function is retained in the biometric unit pipeline after the function returns. It replaces any previous feature set.

The sensor adapter implementation of the [SensorAdapterPushDataToEngine](https://learn.microsoft.com/windows/desktop/api/winbio_adapter/nc-winbio_adapter-pibio_sensor_push_data_to_engine_fn) function should use the following wrapper function (defined in Winbio_adapter.h) to call *EngineAdapterAcceptSampleData*:

```cpp
HRESULT WbioEngineAcceptSampleData(
__inout PWINBIO_PIPELINE Pipeline,
__in PWINBIO_BIR SampleBuffer,
__in SIZE_T SampleSize,
__in WINBIO_BIR_PURPOSE Purpose,
__out PWINBIO_REJECT_DETAIL RejectDetail
);
```

The [WINBIO_BIR](https://learn.microsoft.com/windows/desktop/SecBioMet/winbio-bir) structure that is passed in the *SampleBuffer* parameter is the property of the sensor adapter. Because the sensor adapter controls the lifetime of the **WINBIO_BIR** object, the *EngineAdapterAcceptSampleData* function must not attempt to deallocate the structure or save a pointer to it. By not saving the pointer, you prevent other parts of the engine adapter from attempting to use the **WINBIO_BIR** structure after the *EngineAdapterAcceptSampleData* function returns.

If the **Offset** field of the **StandardDataBlock** member of the [WINBIO_BIR](https://learn.microsoft.com/windows/desktop/SecBioMet/winbio-bir) structure is greater than zero (indicating that the BIR contains a biometric sample in the standard data format), the **BiometricDataFormat** field of the **HeaderBlock** member must be set as follows:

* The **Owner** field must be **WINBIO_ ANSI_381_FORMAT_OWNER**.
* The **Type** field must be **WINBIO_ANSI_381_FORMAT_TYPE**.

This is the only standard data format supported by the Windows Biometric Framework.

The Windows Biometric Framework also assumes that the **HeaderBlock** member (a [WINBIO_BIR_HEADER](https://learn.microsoft.com/windows/desktop/SecBioMet/winbio-bir-header) structure) contains the **DataFlags** and **Purpose** values used by the sensor adapter to capture the sample.

Fingerprint sensors processing fingerprint samples and rejecting bad swipes in the Engine Adapter should also use valid values for **WINBIO_BIR_PURPOSE**.

#### Examples

The following pseudocode shows one possible implementation of this function. The example does not compile. You must adapt it to suit your purpose.

```cpp
//////////////////////////////////////////////////////////////////////////////////////////
//
// EngineAdapterAcceptSampleData
//
// Purpose:
//      Notifies the engine adapter to accept a raw biometric sample and
//      extract a feature set.
//
// Parameters:
//      Pipeline        - Pointer to a WINBIO_PIPELINE structure associated
//                        with the biometric unit performing the operation.
//      SampleBuffer    - Contains the biometric sample to be processed.
//      SampleSize      - Size of the structure returned in the SampleBuffer
//                        parameter.
//      Purpose         - Specifies the intended use of the sample.
//      RejectDetail    - Receives additional information about the failure,
//                        if any, to process a biometric sample.
//
static HRESULT
WINAPI
EngineAdapterAcceptSampleData(
    __inout PWINBIO_PIPELINE Pipeline,
    __in PWINBIO_BIR SampleBuffer,
    __in SIZE_T SampleSize,
    __in WINBIO_BIR_PURPOSE Purpose,
    __out PWINBIO_REJECT_DETAIL RejectDetail
    )
{
    HRESULT hr = S_OK;
    PUCHAR featureSet = NULL;

    // Verify that pointer arguments are not NULL.
    if (!ARGUMENT_PRESENT(Pipeline)     ||
        !ARGUMENT_PRESENT(SampleBuffer) ||
        !ARGUMENT_PRESENT(RejectDetail))
    {
        hr = E_POINTER;
        goto cleanup;
    }

    // Retrieve the context from the pipeline.
    PWINBIO_ENGINE_CONTEXT context =
           (PWINBIO_ENGINE_CONTEXT)Pipeline->EngineContext;

    // Verify that input arguments are valid.
    if (SampleSize == 0 ||
        Purpose == WINBIO_NO_PURPOSE_AVAILABLE)
    {
        hr = E_INVALIDARG;
        goto cleanup;
    }

    // Release any feature set currently attached to the pipeline before
    // creating a new feature set.
    if (context->FeatureSet != NULL)
    {
        _AdapterRelease(context->FeatureSet);
        context->FeatureSet = NULL;
        context->FeatureSetSize = 0;
    }

    // An actual engine adapter would here process the contents of the sample
    // buffer, generate a feature set suitable for the purpose(s) specified
    // by the Purpose parameter, and attach the feature set to the pipeline.
    // The following trivial example, however, creates a feature set simply
    // by making an exact copy of the raw sample.
    // If the sample data cannot be processed, return an HRESULT error code
    // of WINBIO_E_BAD_CAPTURE and set extended error information in the
    // RejectDetail parameter.
    featureSet = (PUCHAR)_AdapterAlloc(SampleSize);
    if (featureSet == NULL)
    {
        hr = E_OUTOFMEMORY;
        goto cleanup;
    }
    RtlCopyMemory(featureSet, SampleBuffer, SampleSize);
    context->FeatureSet = featureSet;
    featureSet = NULL;
    context->FeatureSetSize = SampleSize;

cleanup:

    if (FAILED(hr))
    {
        if (featureSet != NULL)
        {
            _AdapterRelease(featureSet);
        }
    }

    return hr;
}

```

## See also

[EngineAdapterExportEngineData](https://learn.microsoft.com/windows/desktop/api/winbio_adapter/nc-winbio_adapter-pibio_engine_export_engine_data_fn)

[Plug-in Functions](https://learn.microsoft.com/windows/desktop/SecBioMet/plug-in-functions)