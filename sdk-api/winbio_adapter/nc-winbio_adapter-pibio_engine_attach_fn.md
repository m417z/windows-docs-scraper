# PIBIO_ENGINE_ATTACH_FN callback function

## Description

Called by the Windows Biometric Framework when an engine adapter is added to the processing pipeline of the biometric unit. The purpose of this function is to perform any initialization required for later biometric operations.

## Parameters

### `Pipeline` [in, out]

Pointer to a [WINBIO_PIPELINE](https://learn.microsoft.com/windows/desktop/api/winbio_adapter/ns-winbio_adapter-winbio_pipeline) structure associated with the biometric unit performing the operation.

## Return value

If the function succeeds, it returns S_OK. If the function fails, it must return one of the following **HRESULT** values to indicate the error.

| Return code | Description |
| --- | --- |
| **E_POINTER** | The *Pipeline* argument cannot be **NULL**. |
| **E_OUTOFMEMORY** | The operation could not be completed because of insufficient memory. |
| **WINBIO_E_INVALID_DEVICE_STATE** | The **EngineContext** member of the [WINBIO_PIPELINE](https://learn.microsoft.com/windows/desktop/api/winbio_adapter/ns-winbio_adapter-winbio_pipeline) structure pointed to by the *Pipeline* argument is not **NULL** or the **EngineHandle** member is not set to **INVALID_HANDLE_VALUE**. |

## Remarks

This function is called before the storage adapter has been initialized for the biometric unit. Therefore, this function must not call any functions referenced by the [WINBIO_STORAGE_INTERFACE](https://learn.microsoft.com/windows/win32/api/winbio_adapter/ns-winbio_adapter-winbio_storage_interface) structure pointed to by the **StorageInterface** member of the pipeline object.

When implementing this function, you must allocate and manage any resources required by the adapter and attach these to the biometric unit pipeline. To do this, allocate a private **WINBIO_ENGINE_CONTEXT** structure on the heap, initialize it, and set its address in the **EngineContext** member of the pipeline object.

If there is an error during the creation and initialization of engine adapter resources used by this function, you must perform any required cleanup before returning.

If the **EngineContext** field is not **NULL** when this function is called, the pipeline was not properly initialized and you must return **WINBIO_E_INVALID_DEVICE_STATE** to notify the Windows Biometric Framework of the problem.

Similarly, if the **EngineHandle** field does not contain **INVALID_HANDLE_VALUE** when this function is called, you must return **WINBIO_E_INVALID_DEVICE_STATE**.

#### Examples

The following pseudocode shows one possible implementation of this function. The example does not compile. You must adapt it to suit your purpose.

```cpp
//////////////////////////////////////////////////////////////////////////////////////////
//
// EngineAdapterAttach
//
// Purpose:
//      Performs any initialization required for later biometric operations.
//
// Parameters:
//      Pipeline -  Pointer to a WINBIO_PIPELINE structure associated with
//                  the biometric unit performing the operation.
//
static HRESULT
WINAPI
EngineAdapterAttach(
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
    PWINBIO_ENGINE_CONTEXT newContext = NULL;

    // Call a custom function (_AdapterAlloc) to allocate memory to hold the
    // engine adapter context.
    newContext = (PWINBIO_ENGINE_CONTEXT)_AdapterAlloc(sizeof(WINBIO_ENGINE_CONTEXT));
    if (newContext == NULL)
    {
        E_OUTOFMEMORY;
        goto cleanup;
    }

    // Clear the context memory.
    ZeroMemory(newContext, sizeof(WINBIO_ENGINE_CONTEXT));

    // Initialize any required context fields.
    newContext->SomeField = SomeSpecialValue;

    newContext->SomePointerField = _AdapterAlloc(sizeof(SOME_STRUCTURE));
    if (newContext->SomePointerField == NULL)
    {
        E_OUTOFMEMORY;
        goto cleanup;
    }

    // If your adapter supports software-based template hashing, implement the
    // following custom function to open a SHA1 hash object handle and store
    // the handle in the adapter context. Use Cryptography Next Generation (CNG)
    // functions to create the SHA1 hash object.
    hr = _AdapterInitializeCrypto(newContext);
    if (FAILED(hr))
    {
        goto cleanup;
    }

    // If initialization completes successfully, attach the engine context to the
    // processing pipeline of the biometric unit.
    Pipeline->EngineContext = newContext;
    newContext = NULL;

cleanup:
    if (FAILED(hr))
    {
        // If a new context has been created, release any memory
        // pointed to by various data members in the context and
        // then release the context. The following example assumes
        // that your adapter contains a handle
        // for a hash object and a pointer to another object.
        if (newContext != NULL)
        {
            // Close any open CNG handles and release the hash object memory.
            _AdapterCleanupCrypto(newContext);

            // Release any other object pointed to by the context.
            if (newContext->SomePointerField != NULL)
            {
                _AdapterRelease(newContext->SomePointerField);
            }

            // Release the context
            _AdapterRelease(newContext);
        }
    }
    return hr;

}

```

## See also

[EngineAdapterDetach](https://learn.microsoft.com/windows/desktop/api/winbio_adapter/nc-winbio_adapter-pibio_engine_detach_fn)

[Plug-in Functions](https://learn.microsoft.com/windows/desktop/SecBioMet/plug-in-functions)

[SensorAdapterAttach](https://learn.microsoft.com/windows/desktop/api/winbio_adapter/nc-winbio_adapter-pibio_sensor_attach_fn)

[StorageAdapterAttach](https://learn.microsoft.com/windows/desktop/api/winbio_adapter/nc-winbio_adapter-pibio_storage_attach_fn)

[WINBIO_PIPELINE](https://learn.microsoft.com/windows/desktop/api/winbio_adapter/ns-winbio_adapter-winbio_pipeline)