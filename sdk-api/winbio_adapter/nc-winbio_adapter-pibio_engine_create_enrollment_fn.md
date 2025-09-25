# PIBIO_ENGINE_CREATE_ENROLLMENT_FN callback function

## Description

Called by the Windows Biometric Framework to initialize the enrollment object in the biometric unit pipeline.

## Parameters

### `Pipeline` [in, out]

Pointer to a [WINBIO_PIPELINE](https://learn.microsoft.com/windows/desktop/api/winbio_adapter/ns-winbio_adapter-winbio_pipeline) structure associated with the biometric unit performing the operation.

## Return value

If the function succeeds, it returns S_OK. If the function fails, it must return one of the following **HRESULT** values to indicate the error.

| Return code | Description |
| --- | --- |
| **E_POINTER** | The *Pipeline* parameter cannot be **NULL**. |
| **E_OUTOFMEMORY** | There is not enough memory to complete the operation. |

## Remarks

The [EngineAdapterCommitEnrollment](https://learn.microsoft.com/windows/desktop/api/winbio_adapter/nc-winbio_adapter-pibio_engine_commit_enrollment_fn) marks the beginning of an enrollment transaction. If this function succeeds, the Windows Biometric Framework calls [EngineAdapterUpdateEnrollment](https://learn.microsoft.com/windows/desktop/api/winbio_adapter/nc-winbio_adapter-pibio_engine_update_enrollment_fn) to add one or more feature sets to the enrollment object. The Framework then calls *EngineAdapterCommitEnrollment* or [EngineAdapterDiscardEnrollment](https://learn.microsoft.com/windows/desktop/api/winbio_adapter/nc-winbio_adapter-pibio_engine_discard_enrollment_fn) to complete the transaction.

#### Examples

The following pseudocode shows one possible implementation of this function. The example does not compile. You must adapt it to suit your purpose.

```cpp
//////////////////////////////////////////////////////////////////////////////////////////
//
// EngineAdapterCreateEnrollment
//
// Purpose:
//      Initialize the enrollment object in the biometric unit pipeline.
//
// Parameters:
//      Pipeline    - Pointer to a WINBIO_PIPELINE structure associated
//                    with the biometric unit performing the operation
//
static HRESULT
WINAPI
EngineAdapterCreateEnrollment(
    __inout PWINBIO_PIPELINE Pipeline
    )
{
    HRESULT hr = S_OK;

    // Verify that the Pipeline parameter is not NULL.
    if (!ARGUMENT_PRESENT(Pipeline))
    {
        hr = E_POINTER;
        goto cleanup;
    }

    // Retrieve the context from the pipeline.
    PWINBIO_ENGINE_CONTEXT context =
           (PWINBIO_ENGINE_CONTEXT)Pipeline->EngineContext;

    // Return if an enrollment is already in progress. This example assumes that
    // your engine adapter context contains an enrollment object.
    if (context->Enrollment.InProgress == TRUE)
    {
        hr = WINBIO_E_INVALID_DEVICE_STATE;
        goto cleanup;
    }

    // Call a custom function (_AdapterCreateEnrollmentTemplate) to create a
    // new enrollment template and attach it to the engine adapter context.
    hr = _AdapterCreateEnrollmentTemplate(
            context,
            &context->Enrollment
            );
    if (FAILED(hr))
    {
        goto cleanup;
    }

    // Initialize any Enrollment data members not initialized by  the
    // _AdapterCreateEnrollmentTemplate function. This example assumes that
    // your enrollment object contains at a minimum a field that specifies
    // the number of biometric samples and another that specifies whether a
    // new enrollment is in progress.
    context->Enrollment.SampleCount = 0;
    context->Enrollment.InProgress = TRUE;

cleanup:

    return hr;
}

```

## See also

[Plug-in Functions](https://learn.microsoft.com/windows/desktop/SecBioMet/plug-in-functions)