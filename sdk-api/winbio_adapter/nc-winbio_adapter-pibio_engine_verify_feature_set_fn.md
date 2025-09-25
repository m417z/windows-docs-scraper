# PIBIO_ENGINE_VERIFY_FEATURE_SET_FN callback function

## Description

Called by the Windows Biometric Framework to compare the template in the current feature set with a specific template in the database. If the templates are equivalent, the engine adapter must set the Boolean value pointed to by the *Match* parameter to **TRUE**, return the matched template in the *PayloadBlob* parameter, and return a hash of the template in the *HashValue* parameter.

## Parameters

### `Pipeline` [in, out]

Pointer to a [WINBIO_PIPELINE](https://learn.microsoft.com/windows/desktop/api/winbio_adapter/ns-winbio_adapter-winbio_pipeline) structure associated with the biometric unit performing the operation.

### `Identity` [in]

Pointer to a [WINBIO_IDENTITY](https://learn.microsoft.com/windows/desktop/SecBioMet/winbio-identity) structure that contains a GUID or SID that is expected to match that of the template recovered from the database.

### `SubFactor` [in]

A **WINBIO_BIOMETRIC_SUBTYPE** value that is expected to match that of the template recovered from the database.
See the Remarks section for more details.

### `Match` [out]

Pointer to a Boolean value that specifies whether the *Identity* and *SubFactor* parameters match those of the template recovered from the database. **TRUE** specifies that these values match.

### `PayloadBlob` [out]

Address of a variable that receives a pointer to the payload data saved with the template. If there is no payload data, set this value to **NULL**.

### `PayloadBlobSize` [out]

Pointer to a value that receives the size, in bytes, of the buffer specified in the *PayloadBlob* parameter. If there is no payload data stored with the template, set this value to zero.

### `HashValue` [out]

Address of a variable that receives a pointer to the hash of the template. If the engine adapter does not support hash generation, set this value to **NULL**.

### `HashSize` [out]

Pointer to a value that contains the size, in bytes, of the hash specified by the *HashValue* parameter. If the engine adapter does not support hash generation, set this value to zero.

### `RejectDetail` [out]

Pointer to a **WINBIO_REJECT_DETAIL** value that receives additional information if a capture failure prevents the engine from performing a matching operation. If the most-recent capture succeeded, set this parameter to zero. The following values are defined for fingerprint capture

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

If the function succeeds, it returns S_OK. If the function fails, it must return one of the following **HRESULT** values to indicate the error.

| Return code | Description |
| --- | --- |
| **E_POINTER** | A mandatory pointer parameter is **NULL**. |
| ****E_INVALIDARG**** | The value specified in the *SubFactor* parameter is not correct. |
| ****WINBIO_E_BAD_CAPTURE**** | The feature set did not meet the internal requirements of the engine adapter for a verification operation. Further information about the failure is specified by the *RejectDetail* parameter. |
| ****WINBIO_E_NO_MATCH**** | The feature set in the pipeline matches one stored in the database but it does not correspond to the combination of values passed in the *Identity* and *SubFactor* parameters. |

## Remarks

The *SubFactor* parameter specifies the sub-factor associated with the biometric template. The Windows Biometric Framework supports only fingerprint capture and can use the following constants to represent sub-type information.

* WINBIO_ANSI_381_POS_RH_THUMB
* WINBIO_ANSI_381_POS_RH_INDEX_FINGER
* WINBIO_ANSI_381_POS_RH_MIDDLE_FINGER
* WINBIO_ANSI_381_POS_RH_RING_FINGER
* WINBIO_ANSI_381_POS_RH_LITTLE_FINGER
* WINBIO_ANSI_381_POS_LH_THUMB
* WINBIO_ANSI_381_POS_LH_INDEX_FINGER
* WINBIO_ANSI_381_POS_LH_MIDDLE_FINGER
* WINBIO_ANSI_381_POS_LH_RING_FINGER
* WINBIO_ANSI_381_POS_LH_LITTLE_FINGER
* WINBIO_SUBTYPE_ANY

**Important**

Do not attempt to validate the value supplied for the *SubFactor* parameter. The Windows Biometrics Service will validate the supplied value before passing it through to your implementation. If the value is **WINBIO_SUBTYPE_NO_INFORMATION** or **WINBIO_SUBTYPE_ANY**, then validate where appropriate.

The algorithm used to generate the template hash is the one selected by the most recent call, on this pipeline, to the [EngineAdapterSetHashAlgorithm](https://learn.microsoft.com/windows/desktop/api/winbio_adapter/nc-winbio_adapter-pibio_engine_set_hash_algorithm_fn) function.

The hash value returned by this function, if any, is the hash of the enrollment template found in the database, not the matching template attached to the pipeline.

The *PayloadBlob* and *HashValue* buffers are owned and managed by the engine adapter after the [EngineAdapterIdentifyFeatureSet](https://learn.microsoft.com/windows/desktop/api/winbio_adapter/nc-winbio_adapter-pibio_engine_identify_feature_set_fn) function returns successfully. The engine adapter must keep the buffer address valid, for this pipeline, until the next call to [EngineAdapterClearContext](https://learn.microsoft.com/windows/desktop/api/winbio_adapter/nc-winbio_adapter-pibio_engine_clear_context_fn).

#### Examples

The following pseudocode shows one possible implementation of this function. The example does not compile. You must adapt it to suit your purpose.

```cpp
//////////////////////////////////////////////////////////////////////////////////////////
//
// EngineAdapterVerifyFeatureSet
//
// Purpose:
//      Compares the template in the current feature set with a specific
//      template in the database.
//
// Parameters:
//      Pipeline        - Pointer to a WINBIO_PIPELINE structure associated
//                        with the biometric unit performing the operation
//      Identity        - GUID or SID that is expected to match that of the
//                        template recovered from the database
//      SubFactor       - A WINBIO_BIOMETRIC_SUBTYPE value that is expected
//                        to match that of the template recovered from the
//                        database
//      Match           - A Boolean value that specifies whether the Identity
//                        and SubFactor parameters match those of the template
//                        recovered from the database
//      PayloadBlob     - Payload data saved with the template
//      PayloadBlobSize - Size, in bytes, of the buffer specified in the
//                        PayloadBlob parameter
//      HashValue       - Hash of the template
//      HashSize        - Size, in bytes, of the hash specified by the
//                        HashValue parameter
//      RejectDetail    - Receives additional information if a capture failure
//                        prevents the engine from performing a matching operation
//
static HRESULT
WINAPI
EngineAdapterVerifyFeatureSet(
    __inout PWINBIO_PIPELINE Pipeline,
    __in PWINBIO_IDENTITY Identity,
    __in WINBIO_BIOMETRIC_SUBTYPE SubFactor,
    __out PBOOLEAN Match,
    __out PUCHAR *PayloadBlob,
    __out PSIZE_T PayloadBlobSize,
    __out PUCHAR *HashValue,
    __out PSIZE_T HashSize,
    __out PWINBIO_REJECT_DETAIL RejectDetail
    )
{
    HRESULT hr = S_OK;
    WINBIO_STORAGE_RECORD thisRecord;
    BOOLEAN match = FALSE;
    WINBIO_REJECT_DETAIL rejectDetail = 0;

    // Verify that pointer arguments are not NULL.
    if (!ARGUMENT_PRESENT(Pipeline) ||
        !ARGUMENT_PRESENT(Identity) ||
        !ARGUMENT_PRESENT(Match) ||
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
    *Match              = FALSE;
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

    // Query the storage adapter to determine whether the Identity and
    // SubFactor combination specified on input are in the database. If
    // they are not, there can be no match. WbioStorageQueryBySubject
    // is a wrapper function defined in the Winbio_adapter.h header file.
    hr = WbioStorageQueryBySubject( Pipeline, Identity, SubFactor);
    if (FAILED(hr))
    {
        if (hr == WINBIO_E_DATABASE_NO_RESULTS)
        {
            hr = WINBIO_E_NO_MATCH;
        }
        goto cleanup;
    }

    // Position the cursor on the first record in the database.
    // WbioStorageFirstRecord is a wrapper function defined in the
    // Winbio_adapter.h header file.
    hr = WbioStorageFirstRecord( Pipeline );
    if (FAILED(hr))
    {
        goto cleanup;
    }

    // Retrieve the current template record for the Identity and SubFactor
    // combination specified on input.
    hr = WbioStorageGetCurrentRecord( Pipeline, &thisRecord );
    if (FAILED(hr))
    {
        goto cleanup;
    }

    // Call a custom function (_AdapterCompareTemplateToCurrentFeatureSet)
    // to compare the feature set attached to the pipeline with the template
    // retrieved from the database.
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
    if (FAILED(hr))
    {
        goto cleanup;
    }

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

    // Set the return values.
    *Match              = TRUE;
    *PayloadBlob        = thisRecord.PayloadBlob;
    *PayloadBlobSize    = thisRecord.PayloadBlobSize;
    *HashValue          = &context->HashBuffer;
    *HashSize           = context->HashSize;

cleanup:

    if (hr == WINBIO_E_DATABASE_NO_RESULTS)
    {
        hr = WINBIO_E_NO_MATCH;
    }

    return hr;
}

```

## See also

[EngineAdapterIdentifyFeatureSet](https://learn.microsoft.com/windows/desktop/api/winbio_adapter/nc-winbio_adapter-pibio_engine_identify_feature_set_fn)

[Plug-in Functions](https://learn.microsoft.com/windows/desktop/SecBioMet/plug-in-functions)