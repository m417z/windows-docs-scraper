# PIBIO_SENSOR_CLEAR_CONTEXT_FN callback function

## Description

Called by the Windows Biometric Framework to prepare the processing pipeline of the biometric unit for a new operation. This function should flush temporary data from the sensor context and place the sensor adapter into a well-defined initial state.

## Parameters

### `Pipeline` [in, out]

Pointer to the [WINBIO_PIPELINE](https://learn.microsoft.com/windows/desktop/api/winbio_adapter/ns-winbio_adapter-winbio_pipeline) structure associated with the biometric unit performing the operation.

## Return value

If the function succeeds, it returns S_OK. If the function fails, it must return one of the following **HRESULT** values to indicate the error.

| Return code | Description |
| --- | --- |
| **E_POINTER** | The *Pipeline* argument cannot be **NULL**. |

## Remarks

Your implementation of the **SensorAdapterClearContext** function should clear the sample buffer.

#### Examples

The following pseudocode shows one possible implementation of this function. The example does not compile. You must adapt it to suit your purpose.

```cpp
//////////////////////////////////////////////////////////////////////////////////////////
//
// SensorAdapterClearContext
//
// Purpose:
//      Prepare the processing pipeline for a new operation. This function
//      should flush temporary data from the sensor context and place the
//      sensor adapter into a well-defined initial state.
//
// Parameters:
//      Pipeline -  Pointer to a WINBIO_PIPELINE structure associated with
//                  the biometric unit.
//
static HRESULT
WINAPI
SensorAdapterClearContext(
    __inout PWINBIO_PIPELINE Pipeline
    )
{
    // Verify that the Pipeline parameter is not NULL.
    if (!ARGUMENT_PRESENT(Pipeline))
    {
        hr = E_POINTER;
        goto cleanup;
    }

    // Retrieve the context from the pipeline.
    PWINBIO_SENSOR_CONTEXT sensorContext =
        (PWINBIO_SENSOR_CONTEXT)Pipeline->SensorContext;

    // Validate the current state of the sensor.
    if (sensorContext == NULL)
    {
        return WINBIO_E_INVALID_DEVICE_STATE;
    }

    // Change the sensor adapter state and discard any partially completed
    // operations. Depending on the adapter, this can involve changes to state
    // variables or actions implemented in hardware. The following example
    // assumes that your sensor adapter context contains a ULONG data member
    // and pointers to a capture buffer and an attributes buffer.

    sensorContext->SomeField = 0L;

    if (sensorContext->CaptureBuffer != NULL)
    {
        // Zero the capture buffer.
        SecureZeroMemory(
            sensorContext->CaptureBuffer,
            sensorContext->CaptureBufferSize);

        // Release the capture buffer.
        _AdapterRelease(sensorContext->CaptureBuffer);
        sensorContext->CaptureBuffer = NULL;
        sensorContext->CaptureBufferSize = 0;
    }

    if (sensorContext->AttributesBuffer != NULL)
    {
        // Zero the attributes buffer.
        SecureZeroMemory(
            sensorContext->AttributesBuffer,
            sensorContext->AttributesBufferSize);

        // Release the attributes buffer.
        _AdapterRelease(sensorContext->AttributesBuffer);
        sensorContext->AttributesBuffer = NULL;
        sensorContext->AttributesBufferSize = 0;
    }

    // TODO: Perform any other work required to clear the sensor context.

    return S_OK;
}

```

## See also

[EngineAdapterClearContext](https://learn.microsoft.com/windows/desktop/api/winbio_adapter/nc-winbio_adapter-pibio_engine_clear_context_fn)

[Plug-in Functions](https://learn.microsoft.com/windows/desktop/SecBioMet/plug-in-functions)

[StorageAdapterClearContext](https://learn.microsoft.com/windows/desktop/api/winbio_adapter/nc-winbio_adapter-pibio_storage_clear_context_fn)