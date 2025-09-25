# PIBIO_ENGINE_GET_ENROLLMENT_HASH_FN callback function

## Description

Called by the Windows Biometric Framework to retrieve the hash of the completed enrollment template in the pipeline.

## Parameters

### `Pipeline` [in, out]

Pointer to a [WINBIO_PIPELINE](https://learn.microsoft.com/windows/desktop/api/winbio_adapter/ns-winbio_adapter-winbio_pipeline) structure associated with the biometric unit performing the operation.

### `HashValue` [out]

Address of variable that receives a pointer to a byte array that contains the hash of the template.

### `HashSize` [out]

A pointer to a variable that receives the size, in bytes, of the hash pointed to by the *HashValue* parameter.

## Return value

If the function succeeds, it returns S_OK. If the function fails, it must return one of the following **HRESULT** values to indicate the error.

| Return code | Description |
| --- | --- |
| **E_POINTER** | A mandatory pointer parameter is **NULL**. |
| **E_NOTIMPL** | The engine adapter does not support template hash generation. |
| **WINBIO_E_INVALID_DEVICE_STATE** | The pipeline does not contain a completed enrollment template. |

## Remarks

The template hashed by this function must be the completed enrollment template that will be stored in the database when [EngineAdapterCommitEnrollment](https://learn.microsoft.com/windows/desktop/api/winbio_adapter/nc-winbio_adapter-pibio_engine_commit_enrollment_fn) is called. You must not hash one of the intermediate captured samples.

The algorithm used to generate the template hash is that which was selected by the most recent call, on this pipeline, to [EngineAdapterSetHashAlgorithm](https://learn.microsoft.com/windows/desktop/api/winbio_adapter/nc-winbio_adapter-pibio_engine_set_hash_algorithm_fn).

The memory that contains the hash is owned and managed by the engine adapter after the *EngineAdapterGetEnrollmentHash* function returns successfully. The engine adapter must keep the buffer address valid until the Framework calls any of the following functions:

* [EngineAdapterClearContext](https://learn.microsoft.com/windows/desktop/api/winbio_adapter/nc-winbio_adapter-pibio_engine_clear_context_fn)
* [EngineAdapterCommitEnrollment](https://learn.microsoft.com/windows/desktop/api/winbio_adapter/nc-winbio_adapter-pibio_engine_commit_enrollment_fn)
* [EngineAdapterDiscardEnrollment](https://learn.microsoft.com/windows/desktop/api/winbio_adapter/nc-winbio_adapter-pibio_engine_discard_enrollment_fn)

The engine adapter must also maintain a separate hash buffer for each pipeline.

#### Examples

The following pseudocode shows one possible implementation of this function. The example does not compile. You must adapt it to suit your purpose.

```cpp
//////////////////////////////////////////////////////////////////////////////////////////
//
// EngineAdapterGetEnrollmentHash
//
// Purpose:
//      Retrieves the hash of the completed enrollment template in the pipeline.
//
// Parameters:
//      Pipeline        - Pointer to a WINBIO_PIPELINE structure associated
//                        with the biometric unit performing the operation
//      HashValue       - Contains the hash of the template
//      HashSize        - Size, in bytes, of the hash pointed to by the
//                        HashValue parameter
//
static HRESULT
WINAPI
EngineAdapterGetEnrollmentHash(
    __inout PWINBIO_PIPELINE Pipeline,
    __out PUCHAR *HashValue,
    __out PSIZE_T HashSize
    )
{
    ////////////////////////////////////////////////////////////////////////////
    // Return E_NOTIMPL here if your adapter does not support template hashing.
    ////////////////////////////////////////////////////////////////////////////

    HRESULT hr = S_OK;

    // Verify that pointer arguments are not NULL.
    if (!ARGUMENT_PRESENT(Pipeline) ||
        !ARGUMENT_PRESENT(HashValue) ||
        !ARGUMENT_PRESENT(HashSize))
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

    // Initialize the hash.
    *HashValue = NULL;
    *HashSize = 0;

    // If your engine adapter supports template hashing, call a custom function
    // (_AdapterGenerateHashForTemplate) to calculate the hash of the new
    // enrollment template. The hash value should be saved in the adapter
    // context.
    hr = _AdapterGenerateHashForTemplate(
                context,
                context->Enrollment.Template,
                context->Enrollment.TemplateSize,
                context->HashBuffer,
                &context->HashSize
                );
    if (FAILED(hr))
    {
        goto cleanup;
    }

    // Return the hash to the caller.
    *HashValue = context->HashBuffer;
    *HashSize = context->HashSize;

cleanup:

    return hr;
}

```

## See also

[Plug-in Functions](https://learn.microsoft.com/windows/desktop/SecBioMet/plug-in-functions)