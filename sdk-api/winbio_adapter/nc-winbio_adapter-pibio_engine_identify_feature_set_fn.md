# PIBIO_ENGINE_IDENTIFY_FEATURE_SET_FN callback function

## Description

Called by the Windows Biometric Framework to build a template from the current feature set and locate a matching template in the database. If a match can be found, the engine adapter must fill the *Identity*, *SubFactor*, *PayloadBlob* parameters with the appropriate information from the stored template.

## Parameters

### `Pipeline` [in, out]

Pointer to a [WINBIO_PIPELINE](https://learn.microsoft.com/windows/desktop/api/winbio_adapter/ns-winbio_adapter-winbio_pipeline) structure associated with the biometric unit performing the operation.

### `Identity` [out]

Pointer to a [WINBIO_IDENTITY](https://learn.microsoft.com/windows/desktop/SecBioMet/winbio-identity) structure that contains the GUID or SID of the template recovered from the database. This value is returned only if a match is found.

### `SubFactor` [out]

A **WINBIO_BIOMETRIC_SUBTYPE** value that receives the sub-factor associated with the template in the database. See the Remarks section for more details. This value is returned only if a match is found.

### `PayloadBlob` [out]

Address of a variable that receives a pointer to the payload data saved with the template. If there is no payload data, set this value to **NULL**.

### `PayloadBlobSize` [out]

Pointer to a variable that receives the size, in bytes, of the buffer specified by the *PayloadBlob* parameter. If there is no payload data, set this value to zero.

### `HashValue` [out]

Address of a variable that receives a pointer to the generated hash value for the template. If the engine adapter does not support hash generation, set this value to **NULL**.

### `HashSize` [out]

Pointer to a variable that receives the size, in bytes, of the buffer specified by the *HashValue* parameter. If the engine adapter does not support hash generation, set this value to zero.

### `RejectDetail` [out]

Pointer to a variable that receives additional information if a capture failure prevents the engine from performing a matching operation. If the most recent capture succeeded, set this parameter to zero. The following values are defined for fingerprint capture:

* WINBIO_FP_TOO_HIGH
* WINBIO_FP_TOO_LOW
* WINBIO_FP_TOO_LEFT
* WINBIO_FP_TOO_RIGHT
* WINBIO_FP_TOO_FAST
* WINBIO_FP_TOO_SLOW
* WINBIO_FP_POOR_QUALITY
* WINBIO_FP_TOO_SKEWED
* WINBIO_FP_TOO_SHORT
* WINBIO_FP_MERGE_FAILURE

## Return value

If the function succeeds, it returns S_OK to indicate that the last update succeeded and no additional feature sets are required to complete the template. If the function fails, it must return one of the following **HRESULT** values to indicate the error.

| Return code | Description |
| --- | --- |
| **E_POINTER** | The *Pipeline* parameter is **NULL**. |
| ****WINBIO_E_BAD_CAPTURE**** | The feature set did not meet internal requirements of the engine adapter for an identification operation. Further information about the failure is specified by the *RejectDetail* parameter. |
| ****WINBIO_E_UNKNOWN_ID**** | The feature set in the pipeline does not correspond to any identity in the database. |

## Remarks

The algorithm used to generate the template hash is that which was selected by the most recent call, on this pipeline, to [EngineAdapterSetHashAlgorithm](https://learn.microsoft.com/windows/desktop/api/winbio_adapter/nc-winbio_adapter-pibio_engine_set_hash_algorithm_fn).

The hash value returned by this function, if any, is the hash of the enrollment template found in the database, not the matching template attached to the pipeline.

The *PayloadBlob* and *HashValue* buffers are owned and managed by the engine adapter after the *EngineAdapterIdentifyFeatureSet* function returns successfully. The engine adapter must keep the buffer address valid, for this pipeline, until the next call to [EngineAdapterClearContext](https://learn.microsoft.com/windows/desktop/api/winbio_adapter/nc-winbio_adapter-pibio_engine_clear_context_fn).

#### Examples

The following pseudocode shows one possible implementation of this function. The example does not compile. You must adapt it to suit your purpose.

```cpp
//////////////////////////////////////////////////////////////////////////////////////////
//
// EngineAdapterIdentifyFeatureSet
//
// Purpose:
//      Build a template from the current feature set and locate a matching
//      template in the database.
//
// Parameters:
//      Pipeline        - Pointer to a WINBIO_PIPELINE structure associated
//                        with the biometric unit performing the operation
//      Identity        - The GUID or SID of the template recovered from the
//                        database
//      SubFactor       - Sub-factor associated with the template in the
//                        database
//      PayloadBlob     - Payload data saved with the template
//      PayloadBlobSize - Size, in bytes, of the buffer specified by the
//                        PayloadBlob parameter.
//      HashValue       - Hash value for the template
//      HashSize        - Size, in bytes, of the buffer specified by the
//                        HashValue parameter.
//      RejectDetail    - Receives additional information if a capture
//                        failure prevents the engine from performing a matching
//                        operation.
//
static HRESULT
WINAPI
EngineAdapterIdentifyFeatureSet(
    __inout PWINBIO_PIPELINE Pipeline,
    __out PWINBIO_IDENTITY Identity,
    __out PWINBIO_BIOMETRIC_SUBTYPE SubFactor,
    __out PUCHAR *PayloadBlob,
    __out PSIZE_T PayloadBlobSize,
    __out PUCHAR *HashValue,
    __out PSIZE_T HashSize,
    __out PWINBIO_REJECT_DETAIL RejectDetail
    )
{
    HRESULT hr = S_OK;
    SIZE_T recordCount = 0;
    SIZE_T index = 0;
    WINBIO_STORAGE_RECORD thisRecord;
    BOOLEAN match = FALSE;
    DWORD indexVector[NUMBER_OF_TEMPLATE_BINS] = {0};

    // Verify that pointer arguments are not NULL.
    if (!ARGUMENT_PRESENT(Pipeline) ||
        !ARGUMENT_PRESENT(Identity) ||
        !ARGUMENT_PRESENT(SubFactor) ||
        !ARGUMENT_PRESENT(PayloadBlob) ||
        !ARGUMENT_PRESENT(PayloadBlobSize) ||
        !ARGUMENT_PRESENT(HashValue) ||
        !ARGUMENT_PRESENT(HashSize) ||
        !ARGUMENT_PRESENT(RejectDetail))
    {
        hr = E_POINTER;
        goto cleanup;
    }

    // Retrieve the context from the pipeline.
    PWINBIO_ENGINE_CONTEXT context =
           (PWINBIO_ENGINE_CONTEXT)Pipeline->EngineContext;

    // Initialize the return values.
    ZeroMemory( Identity, sizeof(WINBIO_IDENTITY));
    Identity->Type = WINBIO_ID_TYPE_NULL;
    *SubFactor          = WINBIO_SUBTYPE_NO_INFORMATION;
    *PayloadBlob        = NULL;
    *PayloadBlobSize    = 0;
    *HashValue          = NULL;
    *HashSize           = 0;
    *RejectDetail       = 0;

    // The biometric unit cannot perform verification or identification
    // operations while it is performing an enrollment sequence.
    if (context->Enrollment.InProgress == TRUE)
    {
        hr = WINBIO_E_ENROLLMENT_IN_PROGRESS;
        goto cleanup;
    }

    // If your adapter supports index vectors to place templates into buckets,
    // call a custom function (_AdapterCreateIndexVector) to create an index
    // vector from the template data in the feature set. In this example, the
    // engine adapter context attached to the pipeline contains a FeatureSet
    // member.
    hr = _AdapterCreateIndexVector(
                context,
                context->FeatureSet,
                context->FeatureSetSize,
                indexVector,
                NUMBER_OF_TEMPLATE_BINS,
                RejectDetail
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
        // If the template and feature set do not match, return WINBIO_E_NO_MATCH
        // and set the Match parameter to FALSE.
        // If your custom function cannot process the feature set, return
        // WINBIO_E_BAD_CAPTURE and set extended error information in the
        // RejectDetail parameter.
        hr = _AdapterCompareTemplateToCurrentFeatureSet(
                    context,
                    context->FeatureSet,
                    context->FeatureSetSize,
                    thisRecord.TemplateBlob,
                    thisRecord.TemplateBlobSize,
                    &match,
                    RejectDetail
                    );
        if (FAILED(hr) && hr != WINBIO_E_NO_MATCH)
        {
            goto cleanup;
        }
        if (match)
        {
            break;
        }

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

    if (match)
    {
        // If there is a match and if your engine adapter supports template
        // hashing, call a custom function (_AdapterGenerateHashForTemplate)
        // to calculate the hash. Save the hash value in the context area of
        // the engine adapter.
        // Skip this step if your adapter does not support template hashing.
        hr = _AdapterGenerateHashForTemplate(
                    context,
                    thisRecord.TemplateBlob,
                    thisRecord.TemplateBlobSize,
                    context->HashBuffer,
                    &context->HashSize
                    );
        if (FAILED(hr))
        {
            goto cleanup;
        }

        // Return information about the matching template to the caller.
        CopyMemory( Identity, thisRecord.Identity, sizeof(WINBIO_IDENTITY));

        *SubFactor          = thisRecord.SubFactor;
        *PayloadBlob        = thisRecord.PayloadBlob;
        *PayloadBlobSize    = thisRecord.PayloadBlobSize;
        *HashValue          = &context->HashBuffer;
        *HashSize           = context->HashSize;
    }
    else
    {
        hr = WINBIO_E_UNKNOWN_ID;
    }

cleanup:

    if (hr == WINBIO_E_DATABASE_NO_RESULTS)
    {
        hr = WINBIO_E_UNKNOWN_ID;
    }
    return hr;
}

```

## See also

[EngineAdapterVerifyFeatureSet](https://learn.microsoft.com/windows/desktop/api/winbio_adapter/nc-winbio_adapter-pibio_engine_verify_feature_set_fn)

[Plug-in Functions](https://learn.microsoft.com/windows/desktop/SecBioMet/plug-in-functions)