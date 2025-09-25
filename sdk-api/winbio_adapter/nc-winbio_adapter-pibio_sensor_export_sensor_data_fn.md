# PIBIO_SENSOR_EXPORT_SENSOR_DATA_FN callback function

## Description

Called by the Windows Biometric Framework to retrieve a copy of the most recently captured biometric sample formatted as a standard [WINBIO_BIR](https://learn.microsoft.com/windows/desktop/SecBioMet/winbio-bir) structure.

## Parameters

### `Pipeline` [in, out]

Pointer to the [WINBIO_PIPELINE](https://learn.microsoft.com/windows/desktop/api/winbio_adapter/ns-winbio_adapter-winbio_pipeline) structure associated with the biometric unit performing the operation.

### `SampleBuffer` [out]

Address of a variable that receives a pointer to a [WINBIO_BIR](https://learn.microsoft.com/windows/desktop/SecBioMet/winbio-bir) structure that contains the sample.

### `SampleSize` [out]

Pointer to a variable that receives the size, in bytes, of the buffer specified by the *SampleBuffer* parameter.

## Return value

If the function succeeds, it returns S_OK. If the function fails, it must return one of the following **HRESULT** values to indicate the error.

| Return code | Description |
| --- | --- |
| **E_OUTOFMEMORY** | There is not enough memory available to create the [WINBIO_BIR](https://learn.microsoft.com/windows/desktop/SecBioMet/winbio-bir) structure. |
| **E_POINTER** | A mandatory pointer parameter is **NULL**. |
| **WINBIO_E_INVALID_DEVICE_STATE** | The **SensorContext** member of the [WINBIO_PIPELINE](https://learn.microsoft.com/windows/desktop/api/winbio_adapter/ns-winbio_adapter-winbio_pipeline) structure pointed to by the *Pipeline* argument is **NULL**. |
| **WINBIO_E_NO_CAPTURE_DATA** | No capture data exists. |
| **E_NOTIMPL** | This method is not currently implemented. |

## Remarks

You must allocate the buffer to be returned in the *SampleBuffer* parameter from the process heap by using the [HeapAlloc](https://learn.microsoft.com/windows/desktop/api/heapapi/nf-heapapi-heapalloc) function. Once created, this buffer becomes the property of the Windows Biometric Framework. Because the Framework deallocates this memory when finished using it, your implementation of this function must not attempt to deallocate the buffer or save a pointer to it. By not saving the pointer, you prevent other parts of the engine adapter from attempting to use the buffer after this function returns.

#### Examples

The following pseudocode shows one possible implementation of this function. The example does not compile. You must adapt it to suit your purpose.

```cpp
//////////////////////////////////////////////////////////////////////////////////////////
//
// SensorAdapterExportSensorData
//
// Purpose:
//      Retrieves a copy of the most recently captured biometric sample.
//
// Parameters:
//      Pipeline     -  Pointer to a WINBIO_PIPELINE structure associated with
//                      the biometric unit.
//      SampleBuffer -  Address of a variable that receives a pointer to a
//                      WINBIO_BIR structure that contains the sample.
//      SampleSize   -  Pointer to a variable that receives the size, in bytes,
//                      of the buffer specified by the SampleBuffer parameter.
//
static HRESULT
WINAPI
SensorAdapterExportSensorData(
    __inout PWINBIO_PIPELINE Pipeline,
    __out PWINBIO_BIR *SampleBuffer,
    __out SIZE_T *SampleSize
    )
{
    PWINBIO_BIR sampleBuffer = NULL;

    // Verify that pointer arguments are not NULL.
    if (!ARGUMENT_PRESENT(Pipeline) ||
        !ARGUMENT_PRESENT(SampleBuffer) ||
        !ARGUMENT_PRESENT(SampleSize))
    {
        hr = E_POINTER;
        goto cleanup;
    }

    // Retrieve the context from the pipeline.
    PWINBIO_SENSOR_CONTEXT sensorContext =
                 (PWINBIO_SENSOR_CONTEXT)Pipeline->SensorContext;

    // Verify the state of the pipeline.
    if (sensorContext == NULL)
    {
        return WINBIO_E_INVALID_DEVICE_STATE;
    }

    // Determine whether there is capture data to return.
    if (sensorContext->CaptureBuffer == NULL ||
        sensorContext->CaptureBuffer->CaptureData.Size == 0)
    {
        return WINBIO_E_NO_CAPTURE_DATA;
    }

    // Allocate a buffer, copy the data into it, and return
    // the buffer and buffer size to the caller.
    sampleBuffer = _AdapterAlloc(sensorContext->CaptureBuffer->CaptureData.Size);
    if (sampleBuffer == NULL)
    {
        return E_OUTOFMEMORY;
    }
    RtlCopyMemory(
        sampleBuffer,
        sensorContext->CaptureBuffer->CaptureData.Data,
        sensorContext->CaptureBuffer->CaptureData.Size
        );

    *SampleBuffer = sampleBuffer;
    sampleBuffer = NULL;

    *SampleSize = Pipeline->SensorContext->CaptureBuffer->CaptureData.Size;

    return S_OK;
}

```

## See also

[Plug-in Functions](https://learn.microsoft.com/windows/desktop/SecBioMet/plug-in-functions)