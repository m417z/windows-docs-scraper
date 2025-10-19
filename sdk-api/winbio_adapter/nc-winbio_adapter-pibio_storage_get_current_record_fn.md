# PIBIO_STORAGE_GET_CURRENT_RECORD_FN callback function

## Description

Called by the Windows Biometric Framework or by an engine adapter to retrieve the contents of the current record in the pipeline result set.

## Parameters

### `Pipeline` [in, out]

Pointer to the [WINBIO_PIPELINE](https://learn.microsoft.com/windows/desktop/api/winbio_adapter/ns-winbio_adapter-winbio_pipeline) structure associated with the biometric unit performing the operation.

### `RecordContents` [out]

Pointer to a [WINBIO_STORAGE_RECORD](https://learn.microsoft.com/windows/win32/api/winbio_adapter/ns-winbio_adapter-winbio_storage_record) structure that will receive the contents of the record.

## Return value

If the function succeeds, it returns S_OK. If the function fails, it must return one of the following **HRESULT** values to indicate the error.

| Return code | Description |
| --- | --- |
| **E_OUTOFMEMORY** | Memory could not be allocated for the record. |
| **E_POINTER** | A mandatory pointer argument is **NULL**. |
| **WINBIO_E_DATABASE_NO_RESULTS** | There are no records in the result set. |
| **WINBIO_E_INVALID_DEVICE_STATE** | The **StorageContext** member of the pipeline object is **NULL** or the **FileHandle** member is not valid. |

## Remarks

Any addresses returned by this function in the WINBIO_STORAGE_RECORD structure must remain valid until one of the following functions is called:

* [StorageAdapterFirstRecord](https://learn.microsoft.com/windows/desktop/api/winbio_adapter/nc-winbio_adapter-pibio_storage_first_record_fn)
* [StorageAdapterNextRecord](https://learn.microsoft.com/windows/desktop/api/winbio_adapter/nc-winbio_adapter-pibio_storage_next_record_fn)
* [StorageAdapterQueryByContent](https://learn.microsoft.com/windows/desktop/api/winbio_adapter/nc-winbio_adapter-pibio_storage_query_by_content_fn)
* [StorageAdapterQueryBySubject](https://learn.microsoft.com/windows/desktop/api/winbio_adapter/nc-winbio_adapter-pibio_storage_query_by_subject_fn)
* [StorageAdapterClearContext](https://learn.microsoft.com/windows/desktop/api/winbio_adapter/nc-winbio_adapter-pibio_storage_clear_context_fn)

Calling the *StorageAdapterGetCurrentRecord* function does not change the result set pointer. If the pointer is already on the last record in the set, repeatedly calling this function will return the same record contents and an **HRESULT** value of S_OK.

#### Examples

The following pseudocode shows one possible implementation of this function. The example does not compile. You must adapt it to suit your purpose.

```cpp
/////////////////////////////////////////////////////////////////////////////////////////
//
// StorageAdapterGetCurrentRecord
//
// Purpose:
//      Retrieves the contents of the current record in the pipeline result set.
//
// Parameters:
//      Pipeline       - Pointer to a WINBIO_PIPELINE structure associated with
//                       the biometric unit performing the operation.
//      RecordContents - Pointer to a WINBIO_STORAGE_RECORD structure that will receive
//                       the contents of the record.
//
static HRESULT
WINAPI
StorageAdapterGetCurrentRecord(
    __inout PWINBIO_PIPELINE Pipeline,
    __out PWINBIO_STORAGE_RECORD RecordContents
    )
{
    HRESULT hr = S_OK;
    struct _MY_ADAPTER_RECORD_HEADER *recordHeader = NULL;
    LARGE_INTEGER dataOffset = {0};
    SIZE_T allocationSize = 0;

    // Verify that pointer arguments are not NULL.
    if (!ARGUMENT_PRESENT(Pipeline) ||
        !ARGUMENT_PRESENT(RecordContents))
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

    // Call a custom function (_ResultSetGetCurrent) to retrieve the header
    // contents of the current record in the result set. This function should
    // also return the file offset of the template data in the record.
    hr = _ResultSetGetCurrent(
            &storageContext->ResultSet,
            &recordHeader,
            &dataOffset
            );
    if (FAILED(hr))
    {
        goto cleanup;
    }

    RecordContents->Identity = &recordHeader->Identity;
    RecordContents->SubFactor = recordHeader->SubFactor;
    RecordContents->IndexVector = _GetIndexVector(recordHeader);
    RecordContents->IndexElementCount = recordHeader->IndexElementCount;

    // Release any template data buffers created by previous calls to the
    // StorageAdapterGetCurrentRecord function.
    if (storageContext->RawRecordData != NULL)
    {
        _AdapterRelease(storageContext->RawRecordData);
        storageContext->RawRecordData = NULL;
        storageContext->PayloadBlob = NULL;
    }

    if (storageContext->DecryptedTemplate != NULL)
    {
        // You must call SecureZeroMemory to clear any memory that contains
        // a plaintext version of the template data.
        SecureZeroMemory(
            storageContext->DecryptedTemplate,
            storageContext->DecryptedTemplateSize
            );
        _AdapterRelease(storageContext->DecryptedTemplate);
        storageContext->DecryptedTemplate = NULL;
        storageContext->DecryptedTemplateSize = 0;
    }

    // Allocate a buffer for the template and payload portions of the record.
    allocationSize =
        recordHeader->EncryptedTemplateBlobSize +
        recordHeader->PayloadBlobSize;

    storageContext->RawRecordData = (PUCHAR)_AdapterAlloc(allocationSize);
    if (storageContext->RawRecordData == NULL)
    {
        hr = E_OUTOFMEMORY;
        goto cleanup;
    }

    // Call a custom function (_ReadRecordData) that reads the non-header
    // portion of the record.
    hr = _ReadRecordData(
            Pipeline->StorageHandle,
            dataOffset,
            storageContext->RawRecordData,
            (DWORD)allocationSize,
            (PDWORD)&storageContext->RawRecordDataSize
            );
    if (FAILED(hr))
    {
        goto cleanup;
    }

    // Call a custom function (_DecryptTemplate) that decrypts the template
    // data and stores a pointer to the plaintext version in the storage context.
    hr = _DecryptTemplate(
            &storageContext->CryptoContext,
            storageContext->RawRecordData,
            recordHeader->EncryptedTemplateBlobSize,
            &storageContext->DecryptedTemplate,
            &storageContext->DecryptedTemplateSize
            );
    if (FAILED(hr))
    {
        goto cleanup;
    }

    // Set up return values for the caller. These values will remain valid until
    // the next query or get operation.
    RecordContents->TemplateBlob = storageContext->DecryptedTemplate;
    RecordContents->TemplateBlobSize = recordHeader->TemplateBlobSize;

    if (recordHeader->PayloadBlobSize != 0)
    {
        RecordContents->PayloadBlob =
            storageContext->RawRecordData +
            recordHeader->EncryptedTemplateBlobSize;

        RecordContents->PayloadBlobSize = recordHeader->PayloadBlobSize;
    }
    else
    {
        RecordContents->PayloadBlob = NULL;
        RecordContents->PayloadBlobSize = 0;
    }

cleanup:

    if (FAILED(hr))
    {
        if (storageContext->RawRecordData != NULL)
        {
            // Because the raw record data (including the payload blob) is
            // encrypted, it is not necessary to call SecureZeroMemory.
            _AdapterRelease(storageContext->RawRecordData);
            storageContext->RawRecordData = NULL;
            storageContext->PayloadBlob = NULL;
        }
        if (storageContext->DecryptedTemplate != NULL)
        {
            // You must call SecureZeroMemory to clear the plaintext version
            // of the template before releasing it.
            SecureZeroMemory(
                storageContext->DecryptedTemplate,
                storageContext->DecryptedTemplateSize
                );
            _AdapterRelease(storageContext->DecryptedTemplate);
            storageContext->DecryptedTemplate = NULL;
            storageContext->DecryptedTemplateSize = 0;
        }
    }

    return hr;
}

```

## See also

[Plug-in Functions](https://learn.microsoft.com/windows/desktop/SecBioMet/plug-in-functions)