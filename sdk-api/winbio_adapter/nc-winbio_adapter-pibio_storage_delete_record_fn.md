# PIBIO_STORAGE_DELETE_RECORD_FN callback function

## Description

Called by the Windows Biometric Framework to delete one or more templates from the database.

## Parameters

### `Pipeline` [in, out]

Pointer to the [WINBIO_PIPELINE](https://learn.microsoft.com/windows/desktop/api/winbio_adapter/ns-winbio_adapter-winbio_pipeline) structure associated with the biometric unit performing the operation.

### `Identity` [in]

Pointer to a [WINBIO_IDENTITY](https://learn.microsoft.com/windows/desktop/SecBioMet/winbio-identity) structure that contains the GUID or SID of the template to delete.

### `SubFactor` [in]

A **WINBIO_BIOMETRIC_SUBTYPE** value that specifies the sub-factor associated with the template to delete.

## Return value

If the function succeeds, it returns S_OK. If the function fails, it must return one of the following **HRESULT** values to indicate the error.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | The argument specified by the *SubFactor* parameter is not valid or a member of the structure specified by the *Identity* parameter is not valid. |
| **E_OUTOFMEMORY** | Memory could not be allocated for the record header. |
| **E_POINTER** | A mandatory pointer argument is **NULL**. |
| ****WINBIO_E_DATABASE_CORRUPTED**** | There is an unspecified problem with the database. |
| ****WINBIO_E_DATABASE_NO_SUCH_RECORD**** | No matching record could be found in the database. |
| **WINBIO_E_INVALID_DEVICE_STATE** | The **StorageContext** member of the pipeline object is **NULL** or the **FileHandle** member is not valid. |

## Remarks

If the **Type** field of the [WINBIO_IDENTITY](https://learn.microsoft.com/windows/desktop/SecBioMet/winbio-identity) structure pointed to by the *Identity* parameter is set to **WINBIO_IDENTITY_TYPE_WILDCARD** and the *SubFactor* parameter equals **WINBIO_SUBTYPE_ANY**, the storage adapter should delete all records from the database.

**Important**

Do not attempt to validate the value supplied for the *SubFactor* parameter. The Windows Biometrics Service will validate the supplied value before passing it through to your implementation. If the value is **WINBIO_SUBTYPE_NO_INFORMATION** or **WINBIO_SUBTYPE_ANY**, then validate where appropriate.

#### Examples

The following pseudocode shows one possible implementation of this function. The example does not compile. You must adapt it to suit your purpose.

```cpp
/////////////////////////////////////////////////////////////////////////////////////////
//
// StorageAdapterDeleteRecord
//
// Purpose:
//      Deletes one or more templates from the database.
//
// Parameters:
//      Pipeline  -  Pointer to a WINBIO_PIPELINE structure associated with
//                   the biometric unit performing the operation.
//      Identity  -  Pointer to a WINBIO_IDENTITY structure that contains the GUID or
//                   SID of the template to delete.
//      SubFactor -  A WINBIO_BIOMETRIC_SUBTYPE value that specifies the sub-factor
//                   associated with the template to delete.
//
static HRESULT
WINAPI
StorageAdapterDeleteRecord(
    __inout PWINBIO_PIPELINE Pipeline,
    __in PWINBIO_IDENTITY Identity,
    __in WINBIO_BIOMETRIC_SUBTYPE SubFactor
    )
{
    HRESULT hr = S_OK;
    BOOL lockAcquired = FALSE;
    struct _MY_ADAPTER_FILE_HEADER fileHeader = {0};
    SIZE_T remainingRecords = 0;
    LARGE_INTEGER currentRecordOffset = {0};
    struct _MY_ADAPTER_RECORD_HEADER *recordHeader = NULL;
    SIZE_T recordHeaderSize = 0;
    struct _MY_ADAPTER_DPAPI_DATA protectedData = {0};
    SIZE_T deletedRecordCount = 0;

    // Check that pointer arguments are not NULL.
    if (!ARGUMENT_PRESENT(Pipeline) ||
        !ARGUMENT_PRESENT(Identity))
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

    // Check the identity type.
    if (Identity->Type != WINBIO_ID_TYPE_GUID &&
        Identity->Type != WINBIO_ID_TYPE_SID &&
        Identity->Type != WINBIO_ID_TYPE_WILDCARD)
    {
        hr = E_INVALIDARG;
        goto cleanup;
    }

    if (Identity->Type == WINBIO_ID_TYPE_WILDCARD &&
        Identity->Value.Wildcard != WINBIO_IDENTITY_WILDCARD)
    {
        hr = E_INVALIDARG;
        goto cleanup;
    }

    // Some kind of sub-factor information is mandatory, even if it's
    // just a wildcard.
    if (SubFactor == WINBIO_SUBTYPE_NO_INFORMATION)
    {
        hr = E_INVALIDARG;
        goto cleanup;
    }

    // Lock the database for writing (EXCLUSIVE ownership).
    hr = _LockDatabase( Pipeline->StorageHandle, TRUE);
    if (FAILED(hr))
    {
        goto cleanup;
    }
    lockAcquired = TRUE;

    // Read the database header block into memory.
    hr = _ReadFileHeader( Pipeline->StorageHandle, &fileHeader );
    if (FAILED(hr))
    {
        goto cleanup;
    }

    // For this operation, you need to update only the record header
    // area, not the index vector area.
    recordHeaderSize = sizeof(struct _MY_ADAPTER_RECORD_HEADER);

    recordHeader = (struct _MY_ADAPTER_RECORD_HEADER*)_AdapterAlloc( recordHeaderSize );
    if (recordHeader == NULL)
    {
        hr = E_OUTOFMEMORY;
        goto cleanup;
    }

    currentRecordOffset = _MY_ADAPTER_FIRST_RECORD_OFFSET;
    remainingRecords = fileHeader.TotalRecordCount;

    // Scan through all records looking for identity matches.
    while (remainingRecords > 0)
    {
        SIZE_T recordSize = 0;
        BOOLEAN match = FALSE;

        hr = _ReadRecordHeader(
                Pipeline->StorageHandle,
                currentRecordOffset,
                recordHeader,
                recordHeaderSize
                );
        if (FAILED(hr))
        {
            goto cleanup;
        }

        recordSize = recordHeader->RecordSize;

        // Ignore records already marked for deletion.
        if ((recordHeader->Flags & _MY_ADAPTER_FLAG_RECORD_DELETED) == 0)
        {
            hr = _MatchIdentity(
                    Identity,
                    SubFactor,
                    &recordHeader->Identity,
                    recordHeader->SubFactor,
                    &match
                    );
            if (FAILED(hr))
            {
                goto cleanup;
            }

            if (match == TRUE)
            {
                // Mark the record as deleted and call a custom function
                // (_WriteRecordHeader) to write the record header to disk. Space
                // occupied by deleted records should be reclaimed when the last
                // thread that is using the database closes the file. Delaying
                // reclamation until the last thread closes is necessary because
                // there could be other threads whose result sets contain references
                // to the deleted records.
                recordHeader->Flags |= _MY_ADAPTER_FLAG_RECORD_DELETED;
                hr = _WriteRecordHeader(
                        Pipeline->StorageHandle,
                        currentRecordOffset,
                        recordHeader,
                        recordHeaderSize
                        );
                if (FAILED(hr))
                {
                    goto cleanup;
                }
                ++fileHeader.DeletedRecordCount;
                ++deletedRecordCount;
            }
        }

        currentRecordOffset.QuadPart += recordSize;
        --remainingRecords;
    }

    // Write the updated file header to disk.
    hr = _WriteFileHeader(
            Pipeline->StorageHandle,
            &fileHeader
            );
    if (FAILED(hr))
    {
        hr = WINBIO_E_DATABASE_CORRUPTED;
        goto cleanup;
    }

    //  Recompute the file hash and write it to the protected data area.
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

    // Call the SecureZeroMemory function to overwrite the template encryption key
    // on the stack.
    SecureZeroMemory( &protectedData, sizeof(struct _MY_ADAPTER_DPAPI_DATA));

    if (recordHeader != NULL)
    {
        _AdapterRelease(recordHeader);
        recordHeader = NULL;
    }

    if (lockAcquired == TRUE)
    {
        _UnlockDatabase( Pipeline->StorageHandle);
        lockAcquired = FALSE;
    }

    if (SUCCEEDED(hr))
    {
        if (deletedRecordCount == 0)
        {
            hr = WINBIO_E_DATABASE_NO_SUCH_RECORD;
        }
    }

    return hr;
}

```

## See also

[Plug-in Functions](https://learn.microsoft.com/windows/desktop/SecBioMet/plug-in-functions)

[StorageAdapterAddRecord](https://learn.microsoft.com/windows/desktop/api/winbio_adapter/nc-winbio_adapter-pibio_storage_add_record_fn)