# PIBIO_ENGINE_EXPORT_ENGINE_DATA_FN callback function

## Description

Called by the Windows Biometric Framework to retrieve a copy of the most recently processed feature set or template from the engine formatted as a standard [WINBIO_BIR](https://learn.microsoft.com/windows/desktop/SecBioMet/winbio-bir) structure.

## Parameters

### `Pipeline` [in, out]

Pointer to a [WINBIO_PIPELINE](https://learn.microsoft.com/windows/desktop/api/winbio_adapter/ns-winbio_adapter-winbio_pipeline) structure associated with the biometric unit performing the operation.

### `Flags` [in]

A value that specifies the properties of the [WINBIO_BIR](https://learn.microsoft.com/windows/desktop/SecBioMet/winbio-bir) structure returned by the engine. This can be a bitwise **OR** of the following security and processing level flags:

 **WINBIO_DATA_FLAG_PRIVACY**

The data is encrypted.
* **WINBIO_DATA_FLAG_INTEGRITY**
The data is digitally signed or protected by a message authentication code (MAC).
* **WINBIO_DATA_FLAG_SIGNED**
If this flag and the WINBIO_DATA_FLAG_INTEGRITY flag are set, the data is signed. If this flag is not set but the WINBIO_DATA_FLAG_INTEGRITY flag is set, a MAC is computed.
* **WINBIO_DATA_FLAG_RAW**
The data is in the format with which it was captured.
* **WINBIO_DATA_FLAG_INTERMEDIATE**
The data is not raw but has not been completely processed.
* **WINBIO_DATA_FLAG_PROCESSED**
The data has been processed.

### `SampleBuffer` [out]

Address of a variable that receives a pointer to a [WINBIO_BIR](https://learn.microsoft.com/windows/desktop/SecBioMet/winbio-bir) structure that contains the feature set or template.

### `SampleSize` [out]

Pointer to a variable that contains the size, in bytes, of the [WINBIO_BIR](https://learn.microsoft.com/windows/desktop/SecBioMet/winbio-bir) structure returned in the *SampleBuffer* parameter.

## Return value

If the function succeeds, it returns S_OK. If the function fails, it must return one of the following **HRESULT** values to indicate the error.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | The engine adapter does not support the combination of flags specified by the *Flags* parameter. |
| **E_OUTOFMEMORY** | There is not enough memory available to create the [WINBIO_BIR](https://learn.microsoft.com/windows/desktop/SecBioMet/winbio-bir) structure. |
| **E_POINTER** | A mandatory pointer parameter is **NULL**. |
| **WINBIO_E_INVALID_DEVICE_STATE** | The pipeline does not contain the type of data required by the *Flags* parameter. |
| **E_NOTIMPL** | This method is not currently implemented. |

## Remarks

You must allocate the buffer to be returned in the *SampleBuffer* parameter from the process heap by using the [HeapAlloc](https://learn.microsoft.com/windows/desktop/api/heapapi/nf-heapapi-heapalloc) function. After the buffer is created, it becomes the property of the Windows Biometric Framework. Because the Framework deallocates this memory when finished using it, your implementation of this function must not attempt to deallocate the buffer or save a pointer to it. By not saving the pointer, you prevent other parts of the engine adapter from attempting to use the buffer after this function returns.

#### Examples

The following pseudocode shows one possible implementation of this function. The example does not compile. You must adapt it to suit your purpose.

```cpp
//////////////////////////////////////////////////////////////////////////////////////////
//
// EngineAdapterExportEngineData
//
// Purpose:
//      Retrieves a copy of the most recently processed feature set or template.
//
// Parameters:
//      Pipeline        - Pointer to a WINBIO_PIPELINE structure associated
//                        with the biometric unit performing the operation
//      Flags           - Security and processing level flags
//      SampleBuffer    - Contains the feature set or template
//      SampleSize      - Size, in bytes, of the structure returned in the
//                        SampleBuffer parameter.
//
static HRESULT
WINAPI
EngineAdapterExportEngineData(
    __inout PWINBIO_PIPELINE Pipeline,
    __in WINBIO_BIR_DATA_FLAGS Flags,
    __out PWINBIO_BIR *SampleBuffer,
    __out PSIZE_T SampleSize
    )
{
    HRESULT hr = S_OK;
    PWINBIO_BIR birAddress = NULL;
    SIZE_T birSize = 0;

    // Verify that pointer arguments are not NULL.
    if (!ARGUMENT_PRESENT(Pipeline) ||
        !ARGUMENT_PRESENT(SampleBuffer) ||
        !ARGUMENT_PRESENT(SampleSize))
    {
        hr = E_POINTER;
        goto cleanup;
    }

    // Retrieve the context from the pipeline.
    PWINBIO_ENGINE_CONTEXT context =
           (PWINBIO_ENGINE_CONTEXT)Pipeline->EngineContext;

    // At least one processing level flag must be set. Your adapter can also
    // place additional restrictions on supported export formats.
    if (Flags & (WINBIO_DATA_FLAG_RAW |
                 WINBIO_DATA_FLAG_INTERMEDIATE |
                 WINBIO_DATA_FLAG_PROCESSED) == 0)
    {
        hr = E_INVALIDARG;
        goto cleanup;
    }

    // You must implement the _CreateBirFromAdapterData function to extract
    // data from the engine context and create a new WINBIO_BIR structure. The
    // function passes ownership of the new biometric information record (BIR)
    // to the EngineAdapterExportEngineData routine which then passes the BIR
    // to the caller.
    hr = _CreateBirFromAdapterData( context, Flags, &birAddress, &birSize);
    if (SUCCEEDED(hr))
    {
        *SampleBuffer = birAddress;
        *SampleSize = birSize;
    }

cleanup:

    return hr;
}

```

## See also

[EngineAdapterAcceptSampleData](https://learn.microsoft.com/windows/desktop/api/winbio_adapter/nc-winbio_adapter-pibio_engine_accept_sample_data_fn)

[Plug-in Functions](https://learn.microsoft.com/windows/desktop/SecBioMet/plug-in-functions)