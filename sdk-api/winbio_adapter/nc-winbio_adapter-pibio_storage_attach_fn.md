# PIBIO_STORAGE_ATTACH_FN callback function

## Description

Called by the Windows Biometric Framework when a storage adapter is added to the processing pipeline of the biometric unit. The purpose of this function is to perform any initialization required for later biometric operations.

## Parameters

### `Pipeline` [in, out]

Pointer to a [WINBIO_PIPELINE](https://learn.microsoft.com/windows/desktop/api/winbio_adapter/ns-winbio_adapter-winbio_pipeline) structure associated with the biometric unit performing the operation.

## Return value

If the function succeeds, it returns S_OK. If the function fails, it must return one of the following **HRESULT** values to indicate the error.

| Return code | Description |
| --- | --- |
| **E_POINTER** | The *Pipeline* argument cannot be **NULL**. |
| **E_OUTOFMEMORY** | The operation could not be completed because of insufficient memory. |
| **WINBIO_E_INVALID_DEVICE_STATE** | The **StorageContext** member of the [WINBIO_PIPELINE](https://learn.microsoft.com/windows/desktop/api/winbio_adapter/ns-winbio_adapter-winbio_pipeline) structure pointed to by the *Pipeline* argument is not **NULL** or the **StorageHandle** member is not set to **INVALID_HANDLE_VALUE**. |

## Remarks

When implementing this function, you must allocate and manage any resources required by the adapter and attach these to the biometric unit pipeline. To do this, allocate a private **WINIBIO_STORAGE_CONTEXT** structure on the heap, initialize it, and set its address in the **StorageContext** member of the pipeline object.

If the **StorageContext** field is not **NULL** when this function is called, the pipeline was not properly reset by a previous call to [StorageAdapterDetach](https://learn.microsoft.com/windows/desktop/api/winbio_adapter/nc-winbio_adapter-pibio_storage_detach_fn) and you must return **WINBIO_E_INVALID_DEVICE_STATE** to notify the Windows Biometric Framework of the problem.

Similarly, if the **StorageHandle** field does not contain **INVALID_HANDLE_VALUE** when this function is called, you must return **WINBIO_E_INVALID_DEVICE_STATE**.

If there is an error during the creation and initialization of storage adapter resources used by this function, you must perform any required cleanup before returning.

#### Examples

The following pseudocode shows one possible implementation of this function. The example does not compile. You must adapt it to suit your purpose.

```cpp
/////////////////////////////////////////////////////////////////////////////////////////
//
// StorageAdapterAttach
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
StorageAdapterAttach(
    __inout PWINBIO_PIPELINE Pipeline
    )
{
    HRESULT hr = S_OK;
    PWINBIO_STORAGE_CONTEXT newContext = NULL;

    // Verify that the Pipeline parameter is not NULL.
    if (!ARGUMENT_PRESENT(Pipeline))
    {
        hr = E_POINTER;
        goto cleanup;
    }

    if (Pipeline->StorageContext != NULL ||
        Pipeline->StorageHandle != INVALID_HANDLE_VALUE)
    {
        // The pipeline state is not valid. This function should never
        // be called if the pipeline already contains a storage context
        // or a valid storage handle.
        hr = WINBIO_E_INVALID_DEVICE_STATE;
        goto cleanup;
    }

    // Call a custom function (_AdapterAlloc) to allocate memory to hold the
    // sensor adapter context.
    newContext = (PWINBIO_STORAGE_CONTEXT)_AdapterAlloc(sizeof(WINBIO_STORAGE_CONTEXT));
    if (newContext == NULL)
    {
        hr = E_OUTOFMEMORY;
        goto cleanup;
    }

    // Call a custom function to initialize the result set to be used by the next
    // query operation. Initialization typically requires that you clear the result set
    // of any previous query, mark the set as empty, and place the result set cursor
    // in a known state.
    // The result set is attached to the storage context so that it can persist from
    // one storage adapter call to the next.
    hr = _ResultSetInitialize(&newContext->ResultSet);
    if (FAILED(hr))
    {
        goto cleanup;
    }

    // TODO: Initialize any other required context fields (not shown).

    // If initialization completes successfully, attach the context to the
    // processing pipeline of the biometric unit.
    Pipeline->StorageContext = newContext;
    newContext = NULL;

cleanup:

    if (FAILED(hr) && newContext != NULL)
    {
        _ResultSetCleanup(&newContext->ResultSet);
        _AdapterRelease( newContext );
        newContext = NULL;
    }
    return hr;
}

```

## See also

[Plug-in Functions](https://learn.microsoft.com/windows/desktop/SecBioMet/plug-in-functions)

[StorageAdapterDetach](https://learn.microsoft.com/windows/desktop/api/winbio_adapter/nc-winbio_adapter-pibio_storage_detach_fn)