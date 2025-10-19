# PIBIO_STORAGE_ADD_RECORD_FN callback function

## Description

Called by the engine adapter to add a template to the database.

## Parameters

### `Pipeline` [in, out]

Pointer to the [WINBIO_PIPELINE](https://learn.microsoft.com/windows/desktop/api/winbio_adapter/ns-winbio_adapter-winbio_pipeline) structure associated with the biometric unit performing the operation.

### `RecordContents` [in]

Pointer to a [WINBIO_STORAGE_RECORD](https://learn.microsoft.com/windows/win32/api/winbio_adapter/ns-winbio_adapter-winbio_storage_record) structure that contains the template to add.

## Return value

If the function succeeds, it returns S_OK. If the function fails, it must return one of the following **HRESULT** values to indicate the error.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | A member of the structure specified by the *RecordContents* parameter is not valid. |
| **E_POINTER** | A mandatory pointer argument is **NULL**. |
| **WINBIO_E_DATABASE_BAD_INDEX_VECTOR** | The size of the index vector specified in the [WINBIO_STORAGE_RECORD](https://learn.microsoft.com/windows/win32/api/winbio_adapter/ns-winbio_adapter-winbio_storage_record) structure does not match the index size specified when the database was created. |
| **WINBIO_E_DUPLICATE_ENROLLMENT** | The database already contains a template with the combination of values specified by the *Identity* and *SubFactor* parameters. |
| **WINBIO_E_DATABASE_CORRUPTED** | There is an unspecified problem with the database. |
| **WINBIO_E_DATABASE_FULL** | The database is full and no further records can be added. |
| **WINBIO_E_DATABASE_LOCKED** | The database is locked. |
| **WINBIO_E_DATABASE_WRITE_ERROR** | Record addition failed because of an unspecified problem. |
| **WINBIO_E_INVALID_DEVICE_STATE** | The **StorageContext** member of the pipeline object is **NULL** or the **FileHandle** member is not valid. |

## Remarks

The memory identified by the *RecordContents* parameter is the property of the Windows Biometric Framework. The storage adapter must not keep a copy of this pointer, or of any pointers contained in the [WINBIO_STORAGE_RECORD](https://learn.microsoft.com/windows/win32/api/winbio_adapter/ns-winbio_adapter-winbio_storage_record) structure, after returning from *StorageAdapterAddRecord*.

**Important**

Do not attempt to validate the value supplied for the *SubFactor* value of the *RecordContents* parameter. The Windows Biometrics Service will validate the supplied value before passing it through to your implementation. If the value is **WINBIO_SUBTYPE_NO_INFORMATION** or **WINBIO_SUBTYPE_ANY**, then validate where appropriate.

#### Examples

The following pseudocode shows one possible implementation of this function. The example does not compile. You must adapt it to suit your purpose.

```cpp
/////////////////////////////////////////////////////////////////////////////////////////
//
// StorageAdapterAddRecord
//
// Purpose:
//      Adds a template to the database.
//
// Parameters:
//      Pipeline       - Pointer to a WINBIO_PIPELINE structure associated with
//                       the biometric unit performing the operation.
//      RecordContents - Pointer to a WINBIO_STORAGE_RECORD structure that contains
//                       the template to add.
//
static HRESULT
WINAPI
StorageAdapterAddRecord(
    __inout PWINBIO_PIPELINE Pipeline,
    __in PWINBIO_STORAGE_RECORD RecordContents
    )
{
    HRESULT hr = S_OK;
    struct _MY_ADAPTER_RECORD_HEADER *newRecord = NULL;
    SIZE_T newRecordSize = 0;
    BOOL lockAcquired = FALSE;
    ULONG index = 0;
    PUCHAR encryptedTemplateBlob = NULL;
    SIZE_T encryptedTemplateBlobSize = 0;
    struct _MY_ADAPTER_FILE_HEADER fileHeader = {0};
    SIZE_T templateBlobOffset = 0;
    SIZE_T payloadBlobOffset = 0;
    struct _MY_ADAPTER_DPAPI_DATA protectedData = {0};
    SIZE_T duplicateRecordCount = 0;

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

    // Check various values associated with the record contents. The
    // following example code assumes that a database record contains
    // a valid:
    //    Identity
    //    Sub-factor characteristic
    //    Biometric template
    //    Payload associated with the template
    //    Index vector
    //
    if (!ARGUMENT_PRESENT(RecordContents->Identity))
    {
        hr = E_POINTER;
        goto cleanup;
    }

    if (RecordContents->Identity->Type != WINBIO_ID_TYPE_GUID &&
        RecordContents->Identity->Type != WINBIO_ID_TYPE_SID)
    {
        hr = E_INVALIDARG;
        goto cleanup;
    }

    if (RecordContents->SubFactor == WINBIO_SUBTYPE_NO_INFORMATION ||
        RecordContents->SubFactor == WINBIO_SUBTYPE_ANY)
    {
        hr = E_INVALIDARG;
        goto cleanup;
    }

    if (RecordContents->TemplateBlobSize == 0 ||
        !ARGUMENT_PRESENT(RecordContents->TemplateBlob))
    {
        hr = E_INVALIDARG;
        goto cleanup;
    }

    if (RecordContents->PayloadBlobSize > 0 &&
        !ARGUMENT_PRESENT(RecordContents->PayloadBlob))
    {
        hr = E_POINTER;
        goto cleanup;
    }

    if (RecordContents->IndexElementCount != storageContext->IndexElementCount)
    {
        hr = WINBIO_E_DATABASE_BAD_INDEX_VECTOR;
        goto cleanup;
    }

    if (RecordContents->IndexElementCount > 0 &&
        !ARGUMENT_PRESENT(RecordContents->IndexVector))
    {
        hr = E_POINTER;
        goto cleanup;
    }

    // Call a private function (_CheckForDuplicateEnrollments) to query the
    // database for existing records with the same identity and sub-factor
    // values as the new record. If a duplicate is found, return.
    hr = _CheckForDuplicateEnrollments(
            Pipeline,
            RecordContents->Identity,
            RecordContents->SubFactor,
            &duplicateRecordCount
            );
    if (FAILED(hr))
    {
        goto cleanup;
    }
    if (duplicateRecordCount > 0)
    {
        hr = WINBIO_E_DUPLICATE_ENROLLMENT;
        goto cleanup;
    }

    // Call a custom function (_EncryptTemplateData) to encrypt the template
    // data. Do this now so that you can determine how much space will be
    // required to store the encrypted template.
    hr = _EncryptTemplateData(
            &storageContext->CryptoContext,
            RecordContents->TemplateBlob,
            RecordContents->TemplateBlobSize,
            &encryptedTemplateBlob,
            &encryptedTemplateBlobSize
            );
    if (FAILED(hr))
    {
        hr = WINBIO_E_DATABASE_WRITE_ERROR;
        goto cleanup;
    }

    // Call a custom function (_AllocateNewRecord) to allocate memory for the
    // new record. You must allocate enough memory to hold the index vector, the
    // encrypted template, the identity structure, sub-factor information, and the
    // payload blob. You must also allocate enough memory to hold and any other
    // data that will be used by the storage adapter but that will
    // not be made visible to the engine adapter.
    hr = _AllocateNewRecord(
            RecordContents->IndexElementCount,
            encryptedTemplateBlobSize,
            RecordContents->PayloadBlobSize,
            &newRecord,                         // [out] Address of the new record buffer
            &newRecordSize                      // [out] Size of the new record buffer
            );
    if (FAILED(hr))
    {
        goto cleanup;
    }

    // Copy the identity information into the new record.
    CopyMemory(
        &newRecord->Identity,
        RecordContents->Identity,
        sizeof(WINBIO_IDENTITY)
        );

    // Copy the sub-factor information to the new record.
    newRecord->SubFactor = RecordContents->SubFactor;

    // Copy the index vector, if present, into the new record.
    if (RecordContents->IndexElementCount > 0)
    {
        PULONG indexVector = _GetIndexVector(newRecord);
        for (index=0; index < RecordContents->IndexElementCount; ++index)
        {
            indexVector[index] = RecordContents->IndexVector[index];
        }
    }

    // Copy the encrypted template.
    templateBlobOffset =
        sizeof(struct _MY_ADAPTER_RECORD_HEADER) +
        RecordContents->IndexElementCount * sizeof(ULONG);

    newRecord->TemplateBlobSize = RecordContents->TemplateBlobSize;
    newRecord->EncryptedTemplateBlobSize = encryptedTemplateBlobSize;

    CopyMemory(
        (PUCHAR)newRecord + templateBlobOffset,
        encryptedTemplateBlob,
        encryptedTemplateBlobSize
        );

    // Copy the payload blob if present.
    if (RecordContents->PayloadBlobSize > 0)
    {
        payloadBlobOffset =
            templateBlobOffset +
            encryptedTemplateBlobSize;

        newRecord->PayloadBlobSize = RecordContents->PayloadBlobSize;

        CopyMemory(
            (PUCHAR)newRecord + payloadBlobOffset,
            RecordContents->PayloadBlob,
            RecordContents->PayloadBlobSize
            );
    }

    // Call a custom function (_LockDatabase) to lock the database for writing
    // (EXCLUSIVE ownership).
    hr = _LockDatabase(Pipeline->StorageHandle, TRUE);
    if (FAILED(hr))
    {
        goto cleanup;
    }
    lockAcquired = TRUE;

    // Call a custom function (_ReadFileHeader) to read the header block.
    hr = _ReadFileHeader( Pipeline->StorageHandle, &fileHeader );
    if (FAILED(hr))
    {
        goto cleanup;
    }

    // Write the new data record to the first free byte at the end of the
    // active data area in the database file.
    hr = _WriteRecord(
            Pipeline->StorageHandle,
            fileHeader.FirstFreeByte,
            newRecord
            );
    if (FAILED(hr))
    {
        goto cleanup;
    }

    // Update the bookkeeping information in the header and write the header
    // back to the file.
    fileHeader.FirstFreeByte.QuadPart += newRecord->RecordSize;
    ++fileHeader.TotalRecordCount;

    hr = _WriteFileHeader(
            Pipeline->StorageHandle,
            &fileHeader
            );
    if (FAILED(hr))
    {
        hr = WINBIO_E_DATABASE_CORRUPTED;
        goto cleanup;
    }

    // Recompute the file hash and write it to the protected data area in the database
    // file. The hash value is an integrity check on data stored in the file. Note that
    // the DPAPI-protected data block is NOT included in the hash.
    hr = _ReadProtectedData(
            Pipeline->StorageHandle,
            &protectedData
            );
    if (FAILED(hr))
    {
        goto cleanup;
    }

    hr = _ComputeFileHash(
            Pipeline->StorageHandle,
            _MY_ADAPTER_DPAPI_BLOCK_OFFSET,
            (SIZE_T)(fileHeader.FirstFreeByte.QuadPart -
                     _MY_ADAPTER_DPAPI_BLOCK_SIZE),
            protectedData.FileHash,
            _MY_ADAPTER_FILE_HASH_LENGTH,
            (PSIZE_T)&protectedData.FileHashLength
            );
    if (FAILED(hr))
    {
        hr = WINBIO_E_DATABASE_CORRUPTED;
        goto cleanup;
    }

    hr = _WriteProtectedData(
                Pipeline->StorageHandle,
                &protectedData
                );
    if (FAILED(hr))
    {
        hr = WINBIO_E_DATABASE_CORRUPTED;
        goto cleanup;
    }

cleanup:

    // Call the SecureZero function to overwrite the template encryption key
    // on the stack.
    SecureZeroMemory( &protectedData, sizeof(struct _MY_ADAPTER_DPAPI_DATA));

    if (lockAcquired == TRUE)
    {
        _UnlockDatabase( Pipeline->StorageHandle);
        lockAcquired = FALSE;
    }

    if (encryptedTemplateBlob != NULL)
    {
        SecureZeroMemory(encryptedTemplateBlob, encryptedTemplateBlobSize);
        _AdapterRelease(encryptedTemplateBlob);
        encryptedTemplateBlob = NULL;
    }

    if (newRecord != NULL)
    {
        SecureZeroMemory( newRecord, newRecordSize);
        _AdapterRelease(newRecord);
        newRecord = NULL;
    }

    return hr;
}

```

## See also

[Plug-in Functions](https://learn.microsoft.com/windows/desktop/SecBioMet/plug-in-functions)

[StorageAdapterDeleteRecord](https://learn.microsoft.com/windows/desktop/api/winbio_adapter/nc-winbio_adapter-pibio_storage_delete_record_fn)