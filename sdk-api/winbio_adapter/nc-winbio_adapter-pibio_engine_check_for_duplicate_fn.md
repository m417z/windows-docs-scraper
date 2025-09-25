# PIBIO_ENGINE_CHECK_FOR_DUPLICATE_FN callback function

## Description

Called by the Windows Biometric Framework to determine whether a new template in the pipeline duplicates any template already saved in the database regardless of the identity associated with the templates.

## Parameters

### `Pipeline` [in, out]

Pointer to a [WINBIO_PIPELINE](https://learn.microsoft.com/windows/desktop/api/winbio_adapter/ns-winbio_adapter-winbio_pipeline) structure associated with the biometric unit performing the operation.

### `Identity` [out]

Pointer to a [WINBIO_IDENTITY](https://learn.microsoft.com/windows/desktop/SecBioMet/winbio-identity) structure that receives the GUID or SID of the duplicate template stored in the database.

### `SubFactor` [out]

Pointer to a **WINBIO_BIOMETRIC_SUBTYPE** variable that receives the sub-factor associated with the duplicate template in the database.

### `Duplicate` [out]

A pointer to a Boolean value that specifies whether a matching template was found in the database.

## Return value

| Return code | Description |
| --- | --- |
| **E_POINTER** | A mandatory pointer parameter is **NULL**. |
| **WINBIO_E_INVALID_DEVICE_STATE** | There is no enrollment template in the pipeline engine context. |

## Remarks

The Windows Biometric Framework calls this function before committing a new enrollment template to the database of a biometric unit. The purpose of this function is to prevent collisions in the engine adapter matching space. Collisions can result in false-positive matches.

This function should perform a content-based query by using the storage adapter to determine whether the template matches any template already in the database.

If this method finds a duplicate template in the database, it should return the *Identity* and *SubFactor* values for the matching template, set the *Duplicate* parameter to **TRUE**, and return an **HRESULT** value of S_OK.

If this method does not find a matching template in the database, it should set the *Duplicate* parameter to **FALSE** but return an **HRESULT** value of S_OK.

#### Examples

The following pseudocode shows one possible implementation of this function. The example does not compile. You must adapt it to suit your purpose.

```cpp
//////////////////////////////////////////////////////////////////////////////////////////
//
// EngineAdapterCheckForDuplicate
//
// Purpose:
//      Determines whether a new template in the pipeline duplicates any
//      template already saved in the database regardless of the identity
//      associated with the templates.
//
// Parameters:
//      Pipeline    - Pointer to a WINBIO_PIPELINE structure associated
//                    with the biometric unit performing the operation
//      Identity    - GUID or SID of the duplicate template stored in the
//                    database
//      SubFactor   - sub-factor associated with the duplicate template in
//                    the database
//      Duplicate   - Boolean value that specifies whether a matching template
//                    was found in the database
//
static HRESULT
WINAPI
EngineAdapterCheckForDuplicate(
    __inout PWINBIO_PIPELINE Pipeline,
    __out PWINBIO_IDENTITY Identity,
    __out PWINBIO_BIOMETRIC_SUBTYPE SubFactor,
    __out PBOOLEAN Duplicate
    )
{
    HRESULT hr = S_OK;
    WINBIO_REJECT_DETAIL rejectDetail = 0;
    SIZE_T recordCount = 0;
    SIZE_T index = 0;
    WINBIO_STORAGE_RECORD thisRecord;
    BOOLEAN match = FALSE;
    DWORD indexVector[NUMBER_OF_TEMPLATE_BINS] = {0};

    // Verify that pointer arguments are not NULL.
    if (!ARGUMENT_PRESENT(Pipeline)  ||
        !ARGUMENT_PRESENT(Identity)  ||
        !ARGUMENT_PRESENT(SubFactor) ||
        !ARGUMENT_PRESENT(Duplicate))
    {
        hr = E_POINTER;
        goto cleanup;
    }

    // Retrieve the context from the pipeline.
    PWINBIO_ENGINE_CONTEXT context =
           (PWINBIO_ENGINE_CONTEXT)Pipeline->EngineContext;

    // Return if an enrollment is not in progress. This example assumes that
    // an enrollment object is part of your engine context structure.
    if (context->Enrollment.InProgress != TRUE)
    {
        hr = WINBIO_E_INVALID_DEVICE_STATE;
        goto cleanup;
    }

    // Zero the memory pointed to by the Identity argument and set the
    // pointer to NULL.
    ZeroMemory( Identity, sizeof(WINBIO_IDENTITY));
    Identity->Type = WINBIO_ID_TYPE_NULL;

    // Eliminate sub-factor information.
    *SubFactor  = WINBIO_SUBTYPE_NO_INFORMATION;

    // Initialize the Boolean Duplicate argument to FALSE.
    *Duplicate  = FALSE;

    // If your adapter supports index vectors to place templates into buckets,
    // call a custom function (_AdapterCreateIndexVector) to create an index
    // vector from the template data in the feature set. In this example, the
    // engine adapter context attached to the pipeline contains an Enrollment
    // member that references the current template. Your implementation may
    // differ.
    hr = _AdapterCreateIndexVector(
                context,
                context->Enrollment.Template,
                context->Enrollment.TemplateSize,
                indexVector,
                NUMBER_OF_TEMPLATE_BINS,
                &rejectDetail
                );
    if (FAILED(hr))
    {
        goto cleanup;
    }

    // Retrieve the records in the index vector. If your adapter does not support
    // index vectors (the vector length is zero), calling the WbioStorageQueryByContent
    // function will retrieve all records.
    // WbioStorageQueryByContent is a wrapper function in the Winbio_adapter.h
    // header file.
    hr = WbioStorageQueryByContent(
            Pipeline,
            WINBIO_SUBTYPE_ANY,
            indexVector,
            NUMBER_OF_TEMPLATE_BINS
            );
    if (FAILED(hr))
    {
        goto cleanup;
    }

    // Determine the size of the result set. WbioStorageGetRecordCount is a wrapper
    // function in the Winbio_adapter.h header file.
    hr = WbioStorageGetRecordCount( Pipeline, &recordCount);
    if (FAILED(hr))
    {
        goto cleanup;
    }

    // Point the result set cursor at the first record. WbioStorageFirstRecord
    // is a wrapper function in the Winbio_adapter.h header file.
    hr = WbioStorageFirstRecord( Pipeline );
    if (FAILED(hr))
    {
        goto cleanup;
    }

    // Iterate through all records in the result set and determine which record
    // matches the current feature set. WbioStorageGetCurrentRecord is a wrapper
    // function in the Winbio_adapter.h header file.
    for (index = 0; index < recordCount; ++index)
    {
        hr = WbioStorageGetCurrentRecord( Pipeline, &thisRecord );
        if (FAILED(hr))
        {
            goto cleanup;
        }

        // Call a custom function (_AdapterCompareTemplateToCurrentFeatureSet) to
        // compare the feature set attached to the pipeline with the template
        // retrieved from storage.
        // If the template and feature set match, return S_OK and set the match
        // argument to TRUE. If the template and feature set do not match, return
        // S_OK and set the match argument to FALSE. If the function fails for some
        // other reason, return a failure HRESULT.
        hr = _AdapterCompareTemplateToEnrollmentTemplate(
                    context,
                    context->Enrollment.Template,
                    context->Enrollment.TemplateSize,
                    thisRecord.TemplateBlob,
                    thisRecord.TemplateBlobSize,
                    &match
                    );
        if (FAILED(hr))
        {
            goto cleanup;
        }
        if (match)
        {
            break;
        }

        // Retrieve the next record.
        hr = WbioStorageNextRecord( Pipeline );
        if (FAILED(hr))
        {
            if (hr == WINBIO_E_DATABASE_NO_MORE_RECORDS)
            {
                hr = S_OK;
                break;
            }
            else
            {
                goto cleanup;
            }
        }
    }

    // If there is a duplicate template in the database, return information about
    // it to the caller.
    if (match)
    {
        CopyMemory( Identity, thisRecord.Identity, sizeof(WINBIO_IDENTITY));
        *SubFactor = thisRecord.SubFactor;
        *Duplicate = TRUE;
        hr = S_OK;
    }

cleanup:

    // There are no duplicates. This is an acceptable result.
    if (hr == WINBIO_E_DATABASE_NO_RESULTS)
    {
        hr = S_OK;
    }
    return hr;
}

```

## See also

[Plug-in Functions](https://learn.microsoft.com/windows/desktop/SecBioMet/plug-in-functions)