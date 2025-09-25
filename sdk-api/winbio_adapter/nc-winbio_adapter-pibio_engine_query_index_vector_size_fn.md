# PIBIO_ENGINE_QUERY_INDEX_VECTOR_SIZE_FN callback function

## Description

Called by the Windows Biometric Framework to retrieve the size of the index vector used by the engine adapter.

## Parameters

### `Pipeline` [in, out]

Pointer to a [WINBIO_PIPELINE](https://learn.microsoft.com/windows/desktop/api/winbio_adapter/ns-winbio_adapter-winbio_pipeline) structure associated with the biometric unit performing the operation.

### `IndexElementCount` [out]

Address of a variable that receives the number of array elements in the index vector.

## Return value

If the function succeeds, it returns S_OK. If the function fails, it must return one of the following **HRESULT** values to indicate the error.

| Return code | Description |
| --- | --- |
| **E_POINTER** | A mandatory pointer parameter is **NULL**. |

## Remarks

The index vector is used by the engine adapter to index the available biometric templates.

#### Examples

The following pseudocode shows one possible implementation of this function. The example does not compile. You must adapt it to suit your purpose.

```cpp
///////////////////////////////////////////////////////////////////////////////
//
// EngineAdapterQueryIndexVectorSize
//
// Purpose:
//      Called by the Windows Biometric Framework to retrieve the size of
//      the index vector used by the engine adapter.
//
// Parameters:
//      Pipeline            - Pointer to a WINBIO_PIPELINE structure associated
//                            with the biometric unit performing the operation.
//      IndexElementCount   - Address of a variable that receives the number of
//                            elements in the index vector.
//
static HRESULT
WINAPI
EngineAdapterQueryIndexVectorSize(
    __inout PWINBIO_PIPELINE Pipeline,
    __out PSIZE_T IndexElementCount
    )
{
    HRESULT hr = S_OK;

    // Verify that pointer arguments are not NULL.
    if (!ARGUMENT_PRESENT(Pipeline) ||
        !ARGUMENT_PRESENT(IndexElementCount))
    {
        hr = E_POINTER;
        goto cleanup;
    }

    // Specify the number of index vector elements supported by your adapter. This can
    // be any positive value or zero. Return zero if your adapter does not support placing
    // templates into buckets. That is, return zero if your adapter does not support index
    // vectors.
    *IndexElementCount = NUMBER_OF_TEMPLATE_BINS;

cleanup:

    return hr;
}

```

## See also

[Plug-in Functions](https://learn.microsoft.com/windows/desktop/SecBioMet/plug-in-functions)