# PIBIO_STORAGE_QUERY_BY_CONTENT_FN callback function

## Description

Called by the engine adapter to locate templates that match a specified index vector.

## Parameters

### `Pipeline` [in, out]

Pointer to the [WINBIO_PIPELINE](https://learn.microsoft.com/windows/desktop/api/winbio_adapter/ns-winbio_adapter-winbio_pipeline) structure associated with the biometric unit performing the operation.

### `SubFactor` [in]

A **WINBIO_BIOMETRIC_SUBTYPE** value that specifies the sub-factor associated with the template.

### `IndexVector[]`

### `IndexElementCount` [in]

A value that contains the number of elements in the index vector array. This must match the size specified when the database was created. If the database was created with a zero length index, this parameter must be zero.

#### - IndexVector [in]

Pointer to an array of **ULONG** index values. Any template that has a matching index will be returned. If the database was created with a zero length index, this parameter must be **NULL**.

## Return value

If the function succeeds, it returns S_OK. If the function fails, it must return one of the following **HRESULT** values to indicate the error.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | The argument specified by the *SubFactor* parameter is not valid. |
| **E_POINTER** | A mandatory pointer argument is **NULL**. |
| **E_OUTOFMEMORY** | Memory could not be allocated for the record header. |
| **WINBIO_E_DATABASE_BAD_INDEX_VECTOR** | The size of the index vector does not match the index size specified when the database was created. |
| **WINBIO_E_DATABASE_NO_RESULTS** | The query was successful, but no matching records could be found. |
| **WINBIO_E_DATABASE_LOCKED** | The database is locked. |
| **WINBIO_E_DATABASE_READ_ERROR** | An unspecified problem occurred. |
| **WINBIO_E_INVALID_DEVICE_STATE** | The **StorageContext** member of the pipeline object is **NULL** or the **FileHandle** member is not valid. |

## Remarks

If this method returns successfully, the result set in the pipeline is replaced by the results of the query even if the query returns an empty set.

If the database was created with a zero length index vector, the result set will contain every record for which the template sub factor matches the *SubFactor* parameter. In that case, if the caller passes WINBIO_SUBTYPE_ANY for the *SubFactor* parameter, this function returns all records in the database.

After a successful call to this function, the result set cursor should be positioned on the first record in the set.

**Important**

Do not attempt to validate the value supplied for the *SubFactor* parameter. The Windows Biometrics Service will validate the supplied value before passing it through to your implementation. If the value is **WINBIO_SUBTYPE_NO_INFORMATION** or **WINBIO_SUBTYPE_ANY**, then validate where appropriate.

#### Examples

The following pseudocode shows one possible implementation of this function. The example does not compile. You must adapt it to suit your purpose.

```cpp
/////////////////////////////////////////////////////////////////////////////////////////
//
// StorageAdapterQueryByContent
//
// Purpose:
//      Locates templates that match a specified index vector.
//
// Parameters:
//      Pipeline          - Pointer to a WINBIO_PIPELINE structure associated with
//                          the biometric unit performing the operation.
//      SubFactor         - A WINBIO_BIOMETRIC_SUBTYPE value that specifies the sub-factor
//                          associated with the template.
//      IndexVector       - Pointer to an array of ULONG index values.
//      IndexElementCount - A value that contains the number of elements in the index
//                          vector array.
//
static HRESULT
WINAPI
StorageAdapterQueryByContent(
    __inout PWINBIO_PIPELINE Pipeline,
    __in WINBIO_BIOMETRIC_SUBTYPE SubFactor,
    __in ULONG IndexVector[],
    __in SIZE_T IndexElementCount
    )
{
    HRESULT hr = S_OK;
    BOOL lockAcquired = FALSE;
    struct _MY_ADAPTER_FILE_HEADER fileHeader = {0};
    SIZE_T remainingRecords = 0;
    LARGE_INTEGER currentRecordOffset = {0};
    struct _MY_ADAPTER_RECORD_HEADER *recordHeader = NULL;
    SIZE_T recordHeaderSize = 0;

    // Verify that the Pipeline parameter is not NULL.
    if (!ARGUMENT_PRESENT(Pipeline) ||
        !ARGUMENT_PRESENT(IndexVector))
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

    // WINBIO_SUBTYPE_ANY is a valid sub-factor.
    // WINBIO_SUBTYPE_NO_INFORMATION is not a valid sub-factor.
    if (SubFactor == WINBIO_SUBTYPE_NO_INFORMATION)
    {
        hr = E_INVALIDARG;
        goto cleanup;
    }

    // Validate the IndexElementCount argument.
    if (IndexElementCount != storageContext->IndexElementCount)
    {
        hr = WINBIO_E_DATABASE_BAD_INDEX_VECTOR;
        goto cleanup;
    }
    if (storageContext->IndexElementCount > 0 &&
        !ARGUMENT_PRESENT(IndexVector))
    {
        hr = E_POINTER;
        goto cleanup;
    }

    // Clear the result set.
    hr = StorageAdapterClearContext(Pipeline);
    if (FAILED(hr))
    {
        goto cleanup;
    }

    // Lock the database for reading.
    hr = _LockDatabase( Pipeline->StorageHandle, FALSE);
    if (FAILED(hr))
    {
        goto cleanup;
    }
    lockAcquired = TRUE;

    // Read the header block.
    hr = _ReadFileHeader( Pipeline->StorageHandle, &fileHeader );
    if (FAILED(hr))
    {
        goto cleanup;
    }

    // Scan through all records looking for index vector matches.
    recordHeaderSize =
        sizeof(struct _MY_ADAPTER_RECORD_HEADER) +
        (SIZE_T)fileHeader.IndexElementCount * sizeof(ULONG);

    currentRecordOffset = _MY_ADAPTER_FIRST_RECORD_OFFSET;
    remainingRecords = fileHeader.TotalRecordCount;

    while (remainingRecords > 0)
    {
        SIZE_T recordSize = 0;
        BOOLEAN match = FALSE;
        LARGE_INTEGER dataOffset = {0};

        // If you did not give up the current header during the previous
        // iteration of the loop, reuse it.
        if (recordHeader == NULL)
        {
            recordHeader = (struct _MY_ADAPTER_RECORD_HEADER*)_AdapterAlloc( recordHeaderSize );
            if (recordHeader == NULL)
            {
                hr = E_OUTOFMEMORY;
                goto cleanup;
            }
        }
        else
        {
            ZeroMemory(recordHeader, recordHeaderSize);
        }

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

        // Skip records marked for deletion.
        if ((recordHeader->Flags & _MY_ADAPTER_FLAG_RECORD_DELETED) == 0)
        {
            // Call a custom function (_MatchIndexVector) that compares the index
            // vector of the current record with the input index vector.
            hr = _MatchIndexVector(
                    SubFactor,
                    IndexVector,
                    IndexElementCount,
                    recordHeader->SubFactor,
                    _GetIndexVector(recordHeader),
                    storageContext->IndexElementCount,
                    &match
                    );
            if (FAILED(hr))
            {
                goto cleanup;
            }

            if (match == TRUE)
            {
                // Calculate the file offset of this record's data area.
                dataOffset.QuadPart =
                    currentRecordOffset.QuadPart +
                    recordHeader->RecordHeaderSize;

                // Add the matching record to the result set in the pipeline.
                hr = _ResultSetAddElement(
                        &storageContext->ResultSet,
                        recordHeader,
                        dataOffset
                        );
                if (FAILED(hr))
                {
                    goto cleanup;
                }
                // The result set now owns the record header. Set the pointer
                // to NULL.
                recordHeader = NULL;
            }
        }

        currentRecordOffset.QuadPart += recordSize;
        --remainingRecords;
    }

    // If the search was successful, but the result set is empty, return
    // WINBIO_E_DATABASE_NO_RESULTS
    if (SUCCEEDED(hr))
    {
        SIZE_T elementCount = 0;
        hr = _ResultSetGetCount(&storageContext->ResultSet, &elementCount);
    }

cleanup:

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

    if (FAILED(hr))
    {
        // Clear any partial result set from the pipeline.
        StorageAdapterClearContext(Pipeline);
    }

    return hr;
}

```

## See also

[Plug-in Functions](https://learn.microsoft.com/windows/desktop/SecBioMet/plug-in-functions)

[StorageAdapterFirstRecord](https://learn.microsoft.com/windows/desktop/api/winbio_adapter/nc-winbio_adapter-pibio_storage_first_record_fn)

[StorageAdapterGetCurrentRecord](https://learn.microsoft.com/windows/desktop/api/winbio_adapter/nc-winbio_adapter-pibio_storage_get_current_record_fn)

[StorageAdapterGetRecordCount](https://learn.microsoft.com/windows/desktop/api/winbio_adapter/nc-winbio_adapter-pibio_storage_get_record_count_fn)

[StorageAdapterNextRecord](https://learn.microsoft.com/windows/desktop/api/winbio_adapter/nc-winbio_adapter-pibio_storage_next_record_fn)

[StorageAdapterQueryBySubject](https://learn.microsoft.com/windows/desktop/api/winbio_adapter/nc-winbio_adapter-pibio_storage_query_by_subject_fn)