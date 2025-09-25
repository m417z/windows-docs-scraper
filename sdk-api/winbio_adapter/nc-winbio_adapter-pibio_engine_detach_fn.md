# PIBIO_ENGINE_DETACH_FN callback function

## Description

Called by the Windows Biometric Framework immediately before an engine adapter is removed from the processing pipeline of the biometric unit. The purpose of this function is to release adapter specific resources attached to the pipeline.

## Parameters

### `Pipeline` [in, out]

Pointer to a [WINBIO_PIPELINE](https://learn.microsoft.com/windows/desktop/api/winbio_adapter/ns-winbio_adapter-winbio_pipeline) structure associated with the biometric unit performing the operation.

## Return value

If the function succeeds, it returns S_OK. If the function fails, it must return one of the following **HRESULT** values to indicate the error.

| Return code | Description |
| --- | --- |
| **E_POINTER** | The *Pipeline* parameter cannot be **NULL**. |
| **WINBIO_E_INVALID_DEVICE_STATE** | The **EngineContext** field of the [WINBIO_PIPELINE](https://learn.microsoft.com/windows/desktop/api/winbio_adapter/ns-winbio_adapter-winbio_pipeline) structure cannot be **NULL**. |

## Remarks

To prevent memory leaks, your implementation of the *EngineAdapterDetach* function must release the private **WINBIO_ENGINE_CONTEXT** structure pointed to by the **EngineContext** member of the pipeline along with any other resources attached to the engine context.

If the **EngineContext** field in the pipeline object is **NULL** when this function is called, the pipeline was not properly initialized and you must return **WINBIO_E_INVALID_DEVICE_STATE** to notify the Windows Biometric Framework of the problem.

Before returning S_OK, the *EngineAdapterDetach* function must set the **EngineContext** field of the [WINBIO_PIPELINE](https://learn.microsoft.com/windows/desktop/api/winbio_adapter/ns-winbio_adapter-winbio_pipeline) structure to **NULL** and the **EngineHandle** field to **INVALID_HANDLE_VALUE**.

This function is called after the storage adapter has been removed from the pipeline. Therefore, this function must not call any functions referenced by the [WINBIO_STORAGE_INTERFACE](https://learn.microsoft.com/windows/win32/api/winbio_adapter/ns-winbio_adapter-winbio_storage_interface) structure pointed to by the **StorageInterface** member of the pipeline object.

#### Examples

The following pseudocode shows one possible implementation of this function. The example does not compile. You must adapt it to suit your purpose.

```cpp
//////////////////////////////////////////////////////////////////////////////////////////
//
// EngineAdapterDetach
//
// Purpose:
//      Releases adapter specific resources attached to the pipeline.
//
// Parameters:
//      Pipeline -  Pointer to a WINBIO_PIPELINE structure associated with
//                  the biometric unit.
//
static HRESULT
WINAPI
EngineAdapterDetach(
    __inout PWINBIO_PIPELINE Pipeline
    )
{
    PWINBIO_ENGINE_CONTEXT context = NULL;

    // Verify that the Pipeline parameter is not NULL.
    if (!ARGUMENT_PRESENT(Pipeline))
    {
        hr = E_POINTER;
        goto cleanup;
    }

    // Retrieve the context from the pipeline and assign it to a local
    // variable.
    context = (PWINBIO_ENGINE_CONTEXT)Pipeline->EngineContext;
    if (context == NULL)
    {
        goto cleanup;
    }

    // Set the context on the pipeline to NULL.
    Pipeline->EngineContext = NULL;

    // If your adapter supports software-based template hashing and you
    // opened a Cryptography Next Generation (CNG) hash object handle
    // during initialization, implement the following custom function to
    // release the CNG resources.
    _AdapterCleanupCrypto(context);

    // Implement one or more custom routines to release any structures
    // that remain attached to the context block. These structures can
    // include the most recent feature set, the current enrollment template,
    // and other custom defined objects.
    if (context->FeatureSet != NULL)
    {
        _AdapterRelease(context->FeatureSet);
        context->FeatureSet = NULL;
        context->FeatureSetSize = 0;
    }

    if (context->Enrollment.Template != NULL)
    {
        _AdapterRelease(context->Enrollment.Template);
        context->Enrollment.Template = NULL;
        context->Enrollment.TemplateSize = 0;
        context->Enrollment.SampleCount = 0;
    }

    if (context->SomePointerField != NULL)
    {
        _AdapterRelease(context->SomePointerField);
        context->SomePointerField = NULL;
    }

    // Release the context block.
    _AdapterRelease(context);

cleanup:

    return S_OK;
}

```

## See also

[EngineAdapterAttach](https://learn.microsoft.com/windows/desktop/api/winbio_adapter/nc-winbio_adapter-pibio_engine_attach_fn)

[Plug-in Functions](https://learn.microsoft.com/windows/desktop/SecBioMet/plug-in-functions)

[SensorAdapterDetach](https://learn.microsoft.com/windows/desktop/api/winbio_adapter/nc-winbio_adapter-pibio_sensor_detach_fn)