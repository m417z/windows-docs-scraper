# PIBIO_ENGINE_DISCARD_ENROLLMENT_FN callback function

## Description

Called by the Windows Biometric Framework to delete intermediate enrollment state information from the pipeline.

## Parameters

### `Pipeline` [in, out]

Pointer to a [WINBIO_PIPELINE](https://learn.microsoft.com/windows/desktop/api/winbio_adapter/ns-winbio_adapter-winbio_pipeline) structure associated with the biometric unit performing the operation.

## Return value

If the function succeeds, it returns S_OK. If the function fails, it must return the following **HRESULT** value to indicate the error.

| Return code | Description |
| --- | --- |
| **E_POINTER** | The *Pipeline* parameter cannot be **NULL**. |

## Remarks

Your implementation of this function should not save information in the biometric unit database.

#### Examples

The following pseudocode shows one possible implementation of this function. The example does not compile. You must adapt it to suit your purpose.

```cpp
//////////////////////////////////////////////////////////////////////////////////////////
//
// EngineAdapterDiscardEnrollment
//
// Purpose:
//      Deletes intermediate enrollment state information from the pipeline.
//
// Parameters:
//      Pipeline  - Pointer to a WINBIO_PIPELINE structure associated
//                  with the biometric unit performing the operation
//
static HRESULT
WINAPI
EngineAdapterDiscardEnrollment(
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

    // Return if an enrollment is not in progress. This example assumes that
    // an enrollment object is part of your engine context structure.
    if (context->Enrollment.InProgress != TRUE)
    {
        hr = WINBIO_E_INVALID_DEVICE_STATE;
        goto cleanup;
    }

    // Call a custom function (_AdapterDestroyEnrollmentTemplate) to release
    // any objects attached to the enrollment object.
    _AdapterDestroyEnrollmentTemplate(
        context,
        &context->Enrollment
        );

    // If the _AdapterDestroyEnrollmentTemplate function does not reset the
    // InProgress data member, reset it here.
    context->Enrollment.InProgress = FALSE;

cleanup:

    return hr;
}

```

## See also

[Plug-in Functions](https://learn.microsoft.com/windows/desktop/SecBioMet/plug-in-functions)