# PIBIO_ENGINE_QUERY_SAMPLE_HINT_FN callback function

## Description

Called by the Windows Biometric Framework to retrieve the number of correct samples required by the engine adapter to construct an enrollment template.

## Parameters

### `Pipeline` [in, out]

Pointer to a [WINBIO_PIPELINE](https://learn.microsoft.com/windows/desktop/api/winbio_adapter/ns-winbio_adapter-winbio_pipeline) structure associated with the biometric unit performing the operation.

### `SampleHint` [out]

Pointer to a variable that receives the number of required samples.

## Return value

If the function succeeds, it returns S_OK. If the function fails, it must return one of the following **HRESULT** values to indicate the error.

| Return code | Description |
| --- | --- |
| **E_POINTER** | A mandatory pointer parameter is **NULL**. |
| **WINBIO_E_UNSUPPORTED_PROPERTY** | The engine adapter does not support this property. |

## Remarks

If an engine adapter requires a different number of samples in different situations, you should return the largest number. For example, if a fingerprint engine requires more swipes for an index finger than for a thumb, return the number required for the index finger.

The value returned by the *SampleHint* parameter specifies the number of correct samples required. Because of bad captures, the actual number of samples required during enrollment may be larger than the number specified.

#### Examples

The following pseudocode shows one possible implementation of this function. The example does not compile. You must adapt it to suit your purpose.

```cpp
//////////////////////////////////////////////////////////////////////////////////////////
//
// EngineAdapterQuerySampleHint
//
// Purpose:
//      Retrieves the number of correct samples required by the engine adapter
//      to construct an enrollment template.
//
// Parameters:
//      Pipeline    - Pointer to a WINBIO_PIPELINE structure associated
//                    with the biometric unit performing the operation.
//      SampleHint  - Pointer to a variable that receives the number of
//                    required samples.
//
static HRESULT
WINAPI
EngineAdapterQuerySampleHint(
    __inout PWINBIO_PIPELINE Pipeline,
    __out PSIZE_T SampleHint
    )
{
    // Verify that pointer arguments are not NULL.
    if (!ARGUMENT_PRESENT(Pipeline) ||
        !ARGUMENT_PRESENT(SampleHint))
    {
        hr = E_POINTER;
        goto cleanup;
    }

    // The sample hint specified here is a constant but can also be a
    // function of the hardware model or the device settings depending
    // on your adapter.
    // If your adapter does not support this feature, return
    // WINBIO_E_UNSUPPORTED_PROPERTY.
    *SampleHint = SAMPLES_REQUIRED_FOR_ENROLLMENT;

cleanup:

    return hr;
}

```

## See also

[EngineAdapterAcceptSampleData](https://learn.microsoft.com/windows/desktop/api/winbio_adapter/nc-winbio_adapter-pibio_engine_accept_sample_data_fn)

[Plug-in Functions](https://learn.microsoft.com/windows/desktop/SecBioMet/plug-in-functions)