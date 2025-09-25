# PIBIO_ENGINE_CLEAR_CONTEXT_FN callback function

## Description

Called by the Windows Biometric Framework to prepare the processing pipeline of the biometric unit for a new operation. This function should flush temporary data from the engine context and place the engine adapter into a well-defined initial state.

## Parameters

### `Pipeline` [in, out]

Pointer to a [WINBIO_PIPELINE](https://learn.microsoft.com/windows/desktop/api/winbio_adapter/ns-winbio_adapter-winbio_pipeline) structure associated with the biometric unit performing the operation.

## Return value

If the function succeeds, it returns S_OK. If the function fails, it must return one of the following **HRESULT** values to indicate the error.

| Return code | Description |
| --- | --- |
| **E_POINTER** | The *Pipeline* argument cannot be **NULL**. |

## Remarks

This purpose of this function is to reset the context to the state it was in immediately after a call to the [EngineAdapterAttach](https://learn.microsoft.com/windows/desktop/api/winbio_adapter/nc-winbio_adapter-pibio_engine_attach_fn) function. The context is a reusable structure. The **EngineAdapterClearContext** function reinitializes the context but does not remove it from the pipeline.

Typical examples of the objects in the engine adapter context area that should be cleared include the following.

| Object | Description |
| --- | --- |
| Feature set | Contains a description of a biometric sample |
| Enrollment | Tracks the current state of an enrollment transaction. |
| Template | Biometric template created by the feature set or the enrollment object. |
| Comparison | Contains the result of a comparison between the template and the feature set. |
| Index vector | Contains a set of index values associated with the template. |

#### Examples

The following pseudocode shows one possible implementation of this function. The example does not compile. You must adapt it to suit your purpose.

```cpp
//////////////////////////////////////////////////////////////////////////////////////////
//
// EngineAdapterClearContext
//
// Purpose:
//      Prepares the processing pipeline of the biometric unit for a
//      new operation.
//
// Parameters:
//      Pipeline -  Pointer to a WINBIO_PIPELINE structure associated with
//                  the biometric unit.
//
static HRESULT
WINAPI
EngineAdapterClearContext(
    __inout PWINBIO_PIPELINE Pipeline
    )
{
    // Verify that the Pipeline parameter is not NULL.
    if (!ARGUMENT_PRESENT(Pipeline))
    {
        hr = E_POINTER;
        goto cleanup;
    }

    // Retrieve the context from the pipeline.
    PWINBIO_ENGINE_CONTEXT context =
           (PWINBIO_ENGINE_CONTEXT)Pipeline->EngineContext;

    if (context == NULL)
    {
        goto cleanup;
    }

    // Change the engine adapter state and discard any partially completed
    // operations. Depending on the adapter, this can involve changes to state
    // variables or actions implemented in hardware. The following example
    // assumes that your engine adapter context contains a ULONG data member
    // and pointers to a feature set and an enrollment object.

    context->SomeField = 0L;

    if (context->FeatureSet != NULL)
    {
        // Zero the feature set if it contains unencrypted biometric data.
        SecureZeroMemory(
            context->FeatureSet,
            context->FeatureSetSize);

        // Release the feature set.
        _AdapterRelease(context->FeatureSet);
        context->FeatureSet = NULL;
        context->FeatureSetSize = 0;
    }

    if (context->Enrollment.Template != NULL)
    {
        // Zero the template if it contains unencrypted biometric data.
        SecureZeroMemory(
            context->Enrollment.Template,
            context->Enrollment.TemplateSize);

        // Release the template.
        _AdapterRelease(context->Enrollment.Template);
        context->Enrollment.Template = NULL;
        context->Enrollment.TemplateSize = 0;

        // Release other data members attached to the enrollment object.
        context->Enrollment.SampleCount = 0;
        context->Enrollment.InProgress = FALSE;
    }

cleanup:

    return S_OK;
}
```

## See also

[Plug-in Functions](https://learn.microsoft.com/windows/desktop/SecBioMet/plug-in-functions)

[SensorAdapterClearContext](https://learn.microsoft.com/windows/desktop/api/winbio_adapter/nc-winbio_adapter-pibio_sensor_clear_context_fn)

[StorageAdapterClearContext](https://learn.microsoft.com/windows/desktop/api/winbio_adapter/nc-winbio_adapter-pibio_storage_clear_context_fn)