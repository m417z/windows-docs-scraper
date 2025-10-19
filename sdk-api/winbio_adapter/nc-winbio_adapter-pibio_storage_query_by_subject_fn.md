# PIBIO_STORAGE_QUERY_BY_SUBJECT_FN callback function

## Description

Called by the Windows Biometric Framework or by the engine adapter to locate templates that match a specified identity and sub-factor.

## Parameters

### `Pipeline` [in, out]

Pointer to the [WINBIO_PIPELINE](https://learn.microsoft.com/windows/desktop/api/winbio_adapter/ns-winbio_adapter-winbio_pipeline) structure associated with the biometric unit performing the operation.

### `Identity` [in]

Pointer to a [WINBIO_IDENTITY](https://learn.microsoft.com/windows/desktop/SecBioMet/winbio-identity) structure that contains the GUID or SID to be located. If the **Type** field of this structure contains **WINBIO_IDENTITY_TYPE_WILDCARD**, the query returns every template that matches the *SubFactor* parameter.

### `SubFactor` [in]

A **WINBIO_BIOMETRIC_SUBTYPE** value that specifies the sub-factor to be located. If this value is **WINBIO_SUBTYPE_ANY**, the query returns every template that matches the *Identity* parameter.

## Return value

If the function succeeds, it returns S_OK. If the function fails, it must return one of the following **HRESULT** values to indicate the error.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | The argument specified by the *SubFactor* parameter is not valid or a member of the structure specified by the *Identity* parameter is not valid. |
| **E_POINTER** | A mandatory pointer argument is **NULL**. |
| **WINBIO_E_DATABASE_NO_RESULTS** | The query was successful, but no matching records could be found. |
| **WINBIO_E_DATABASE_LOCKED** | The database is locked. |
| **WINBIO_E_DATABASE_READ_ERROR** | An unspecified problem occurred. |
| **WINBIO_E_INVALID_DEVICE_STATE** | The **StorageContext** member of the pipeline object is **NULL** or the **FileHandle** member is not valid. |

## Remarks

If this method returns successfully, the result set in the pipeline is replaced by the results of the query even if the query returns an empty set.

Callers of this function should be able to retrieve all records by:

* Passing a [WINBIO_IDENTITY](https://learn.microsoft.com/windows/desktop/SecBioMet/winbio-identity) structure in the *Identity* parameter with the **Type** field set to **WINBIO_IDENTITY_TYPE_WILDCARD**.
* Passing **WINBIO_SUBTYPE_ANY** in the *SubFactor* parameter.

After a successful call to this function, the result set cursor should be positioned on the first record in the set.

**Important**

Do not attempt to validate the value supplied for the *SubFactor* parameter. The Windows Biometrics Service will validate the supplied value before passing it through to your implementation. If the value is **WINBIO_SUBTYPE_NO_INFORMATION** or **WINBIO_SUBTYPE_ANY**, then validate where appropriate.

#### Examples

The following pseudocode shows one possible implementation of this function. The example does not compile. You must adapt it to suit your purpose.

```cpp
/////////////////////////////////////////////////////////////////////////////////////////
//
// StorageAdapterQueryBySubject
//
// Purpose:
//      Locates templates that match a specified identity and sub-factor.
//
// Parameters:
//      Pipeline  -  Pointer to a WINBIO_PIPELINE structure associated with
//                   the biometric unit performing the operation.
//      Identity  -  Pointer to a WINBIO_IDENTITY structure that contains the GUID
//                   or SID to be located.
//      SubFactor -  A WINBIO_BIOMETRIC_SUBTYPE value that specifies the sub-factor
//                   to be located.
//
static HRESULT
WINAPI
StorageAdapterQueryBySubject(
    __inout PWINBIO_PIPELINE Pipeline,
    __in PWINBIO_IDENTITY Identity,
    __in WINBIO_BIOMETRIC_SUBTYPE SubFactor
    )
{
    HRESULT hr = S_OK;
    SIZE_T recordCount = 0;

    // Verify that pointer arguments are not NULL.
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

    // Verify the Identity argument.
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

    // WINBIO_SUBTYPE_ANY is a valid sub-factor.
    // WINBIO_SUBTYPE_NO_INFORMATION is not a valid sub-factor.
    if (SubFactor == WINBIO_SUBTYPE_NO_INFORMATION)
    {
        hr = E_INVALIDARG;
        goto cleanup;
    }

    // Call a custom function (_FindAllMatchingRecords) that compares the
    // identity and sub-factor values from the caller to the identity and
    // sub-factor values of every record in the database and adds the matching
    // database records to the result set in the pipeline.
    hr = _FindAllMatchingRecords(
            Pipeline,
            Identity,
            SubFactor,
            &recordCount
            );
    if (FAILED(hr))
    {
        goto cleanup;
    }
    if (recordCount == 0)
    {
        hr = WINBIO_E_DATABASE_NO_RESULTS;
        goto cleanup;
    }

cleanup:

    return hr;
}

```

## See also

[Plug-in Functions](https://learn.microsoft.com/windows/desktop/SecBioMet/plug-in-functions)

[StorageAdapterFirstRecord](https://learn.microsoft.com/windows/desktop/api/winbio_adapter/nc-winbio_adapter-pibio_storage_first_record_fn)

[StorageAdapterGetCurrentRecord](https://learn.microsoft.com/windows/desktop/api/winbio_adapter/nc-winbio_adapter-pibio_storage_get_current_record_fn)

[StorageAdapterGetRecordCount](https://learn.microsoft.com/windows/desktop/api/winbio_adapter/nc-winbio_adapter-pibio_storage_get_record_count_fn)

[StorageAdapterNextRecord](https://learn.microsoft.com/windows/desktop/api/winbio_adapter/nc-winbio_adapter-pibio_storage_next_record_fn)

[StorageAdapterQueryByContent](https://learn.microsoft.com/windows/desktop/api/winbio_adapter/nc-winbio_adapter-pibio_storage_query_by_content_fn)