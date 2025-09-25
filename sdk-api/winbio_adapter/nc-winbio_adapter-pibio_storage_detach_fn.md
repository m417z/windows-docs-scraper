# PIBIO_STORAGE_DETACH_FN callback function

## Description

Called by the Windows Biometric Framework immediately before a storage adapter is removed from the processing pipeline of the biometric unit. The purpose of this function is to release adapter specific resources attached to the pipeline.

## Parameters

### `Pipeline` [in, out]

Pointer to a [WINBIO_PIPELINE](https://learn.microsoft.com/windows/desktop/api/winbio_adapter/ns-winbio_adapter-winbio_pipeline) structure associated with the biometric unit performing the operation.

## Return value

If the function succeeds, it returns S_OK. If the function fails, it must return one of the following **HRESULT** values to indicate the error.

| Return code | Description |
| --- | --- |
| **E_POINTER** | The *Pipeline* parameter cannot be **NULL**. |
| **WINBIO_E_INVALID_DEVICE_STATE** | The **StorageContext** field of the [WINBIO_PIPELINE](https://learn.microsoft.com/windows/desktop/api/winbio_adapter/ns-winbio_adapter-winbio_pipeline) structure cannot be **NULL**. |

## Remarks

To prevent memory leaks, your implementation of the *StorageAdapterDetach* function must release the private **WINBIO_STORAGE_CONTEXT** structure pointed to by the **StorageContext** member of the pipeline along with any other resources attached to the storage context.

If the **StorageContext** field in the pipeline object is **NULL** when this function is called, the pipeline was not properly initialized and you must return **WINBIO_E_INVALID_DEVICE_STATE** to notify the Windows Biometric Framework of the problem.

Before returning S_OK, this function must set the **StorageContext** field of the [WINBIO_PIPELINE](https://learn.microsoft.com/windows/desktop/api/winbio_adapter/ns-winbio_adapter-winbio_pipeline) structure to **NULL** and the **StorageHandle** field to **INVALID_HANDLE_VALUE**.

#### Examples

The following pseudocode shows one possible implementation of this function. The example does not compile. You must adapt it to suit your purpose.

```cpp
/////////////////////////////////////////////////////////////////////////////////////////
//
// StorageAdapterDetach
//
// Purpose:
//      Release adapter specific resources attached to the pipeline.
//
// Parameters:
//      Pipeline -  Pointer to a WINBIO_PIPELINE structure associated with
//                  the biometric unit performing the operation.
//
static HRESULT
WINAPI
StorageAdapterDetach(
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
    PWINBIO_STORAGE_CONTEXT storageContext =
           (PWINBIO_STORAGE_CONTEXT)Pipeline->StorageContext;

    // Verify the pipeline state.
    if (storageContext == NULL)
    {
        // The pipeline state is not valid. This function should never
        // be called if the storage context in the pipeline is already
        // closed.
        hr = WINBIO_E_INVALID_DEVICE_STATE;
        goto cleanup;
    }

    // Release any structures attached to the context block.
    StorageAdapterClearContext(Pipeline);

    // Close the database.
    StorageAdapterCloseDatabase(Pipeline);

    // Remove the context from the pipeline.
    Pipeline->StorageContext = NULL;
    Pipeline->StorageHandle = INVALID_HANDLE_VALUE;

    // Clear the result set. Depending on your implementation, this action
    // can be performed by the StorageAdapterClearContext function called
    // earlier.
    ResultSetCleanup(&storageContext->ResultSet);

    // Release the adapter context.
    _AdapterRelease( storageContext );
    storageContext = NULL;

cleanup:

    return hr;
}

```

## See also

[Plug-in Functions](https://learn.microsoft.com/windows/desktop/SecBioMet/plug-in-functions)

[StorageAdapterAttach](https://learn.microsoft.com/windows/desktop/api/winbio_adapter/nc-winbio_adapter-pibio_storage_attach_fn)