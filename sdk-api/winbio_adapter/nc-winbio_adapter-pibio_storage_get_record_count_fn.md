# PIBIO_STORAGE_GET_RECORD_COUNT_FN callback function

## Description

Called by the Windows Biometric Framework or by the engine adapter to retrieve the number of template records in the pipeline result set.

## Parameters

### `Pipeline` [in, out]

Pointer to a [WINBIO_PIPELINE](https://learn.microsoft.com/windows/desktop/api/winbio_adapter/ns-winbio_adapter-winbio_pipeline) structure associated with the biometric unit performing the operation.

### `RecordCount` [out]

Pointer to a variable that receives the number of template records in the result set.

## Return value

If the function succeeds, it returns S_OK. If the function fails, it must return one of the following **HRESULT** values to indicate the error.

| Return code | Description |
| --- | --- |
| **E_POINTER** | A mandatory pointer argument is **NULL**. |
| **WINBIO_E_DATABASE_NO_RESULTS** | The query was successful, but no matching records could be found. |
| **WINBIO_E_INVALID_DEVICE_STATE** | The **StorageContext** member of the pipeline object is **NULL** or the **FileHandle** member is not valid. |

## Remarks

The number of records currently in the result set is determined by the most recent call to the [StorageAdapterQueryByContent](https://learn.microsoft.com/windows/desktop/api/winbio_adapter/nc-winbio_adapter-pibio_storage_query_by_content_fn) or the [StorageAdapterQueryBySubject](https://learn.microsoft.com/windows/desktop/api/winbio_adapter/nc-winbio_adapter-pibio_storage_query_by_subject_fn) function.

#### Examples

The following pseudocode shows one possible implementation of this function. The example does not compile. You must adapt it to suit your purpose.

```cpp
/////////////////////////////////////////////////////////////////////////////////////////
//
// StorageAdapterGetRecordCount
//
// Purpose:
//      Retrieves the number of template records in the pipeline result set.
//
// Parameters:
//      Pipeline    -  Pointer to a WINBIO_PIPELINE structure associated with
//                     the biometric unit performing the operation.
//      RecordCount -  Pointer to a variable that receives the number of template
//                     records in the result set.
//
static HRESULT
WINAPI
StorageAdapterGetRecordCount(
    __inout PWINBIO_PIPELINE Pipeline,
    __out PSIZE_T RecordCount
    )
{
    HRESULT hr = S_OK;

    // Verify that pointer arguments are not NULL.
    if (!ARGUMENT_PRESENT(Pipeline) ||
        !ARGUMENT_PRESENT(RecordCount))
    {
        hr = E_POINTER;
        goto cleanup;
    }

    // Retrieve the context from the pipeline.
    PWINBIO_STORAGE_CONTEXT storageContext = (PWINBIO_STORAGE_CONTEXT)Pipeline->StorageContext;

    // Verify the pipeline state.
    if (storageContext == NULL || storageContext->FileHandle == INVALID_HANDLE_VALUE)
    {
        hr =  WINBIO_E_INVALID_DEVICE_STATE;
        goto cleanup;
    }

    // Call a custom function (_ResultSetGetCount) to retrieve the number of
    // records that the most recent query left in the result set.
    hr = _ResultSetGetCount( &storageContext->ResultSet, RecordCount);

cleanup:

    return hr;
}

```

## See also

[Plug-in Functions](https://learn.microsoft.com/windows/desktop/SecBioMet/plug-in-functions)

[StorageAdapterQueryByContent](https://learn.microsoft.com/windows/desktop/api/winbio_adapter/nc-winbio_adapter-pibio_storage_query_by_content_fn)

[StorageAdapterQueryBySubject](https://learn.microsoft.com/windows/desktop/api/winbio_adapter/nc-winbio_adapter-pibio_storage_query_by_subject_fn)