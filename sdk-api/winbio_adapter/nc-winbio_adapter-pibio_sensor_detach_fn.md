# PIBIO_SENSOR_DETACH_FN callback function

## Description

Called by the Windows Biometric Framework immediately before a sensor adapter is removed from the processing pipeline of the biometric unit. The purpose of this function is to release adapter specific resources attached to the pipeline.

## Parameters

### `Pipeline` [in, out]

Pointer to the [WINBIO_PIPELINE](https://learn.microsoft.com/windows/desktop/api/winbio_adapter/ns-winbio_adapter-winbio_pipeline) structure associated with the biometric unit performing the operation.

## Return value

If the function succeeds, it returns S_OK. If the function fails, it must return one of the following **HRESULT** values to indicate the error.

| Return code | Description |
| --- | --- |
| **E_POINTER** | The *Pipeline* parameter cannot be **NULL**. |
| **WINBIO_E_INVALID_DEVICE_STATE** | The **SensorContext** field of the [WINBIO_PIPELINE](https://learn.microsoft.com/windows/desktop/api/winbio_adapter/ns-winbio_adapter-winbio_pipeline) structure cannot be **NULL**. |

## Remarks

To prevent memory leaks, your implementation of the *SensorAdapterDetach* function must release the private **WINBIO_SENSOR_CONTEXT** structure pointed to by the **SensorContext** member of the pipeline along with any other resources attached to the sensor context.

If the **SensorContext** field in the pipeline object is **NULL** when this function is called, the pipeline was not properly initialized and you must return **WINBIO_E_INVALID_DEVICE_STATE** to notify the Windows Biometric Framework of the problem.

Before returning S_OK, this function must set the **SensorContext** field of the [WINBIO_PIPELINE](https://learn.microsoft.com/windows/desktop/api/winbio_adapter/ns-winbio_adapter-winbio_pipeline) structure to **NULL**.

Because this function is called after the storage and engine adapters have been removed from the pipeline, your implementation of this function must not call any functions referenced by the [WINBIO_ENGINE_INTERFACE](https://learn.microsoft.com/windows/win32/api/winbio_adapter/ns-winbio_adapter-winbio_storage_interface) or [WINBIO_STORAGE_INTERFACE](https://learn.microsoft.com/windows/desktop/api/winbio_adapter/ns-winbio_adapter-winbio_storage_interface) structures pointed to by the **EngineInterface** and **StorageInterface** members of the pipeline object.

Because the **SensorHandle** member of the [WINBIO_PIPELINE](https://learn.microsoft.com/windows/desktop/api/winbio_adapter/ns-winbio_adapter-winbio_pipeline) structure will contain a valid handle even after *SensorAdapterDetach* is called, you can use the handle to access the sensor device if necessary. This function should not close the sensor handle. The Windows biometric Framework will do so after *SensorAdapterDetach* returns.

#### Examples

The following pseudocode shows one possible implementation of this function. The example does not compile. You must adapt it to suit your purpose.

```cpp
//////////////////////////////////////////////////////////////////////////////////////////
//
// SensorAdapterDetach
//
// Purpose:
//      Cancels all pending sensor operations.
//
// Parameters:
//      Pipeline -  Pointer to a WINBIO_PIPELINE structure associated with
//                  the biometric unit.
//
static HRESULT
WINAPI
SensorAdapterDetach(
    __inout PWINBIO_PIPELINE Pipeline
    )
{
    PWINBIO_SENSOR_CONTEXT sensorContext = NULL;

    // Verify that the Pipeline parameter is not NULL.
    if (!ARGUMENT_PRESENT(Pipeline))
    {
        hr = E_POINTER;
        goto cleanup;
    }

    // Validate the current state of the sensor.
    if (Pipeline->SensorContext == NULL)
    {
        return WINBIO_E_INVALID_DEVICE_STATE;
    }

    // Cancel any pending I/O to the device.
    SensorAdapterCancel(Pipeline);

    // Take ownership of the sensor context from the pipeline.
    sensorContext = (PWINBIO_SENSOR_CONTEXT)Pipeline->SensorContext;
    Pipeline->SensorContext = NULL;

    // Release any structures that remain attached to the context block.
    // The following example assumes that your sensor adapter context
    // contains pointers to a capture buffer and an attributes buffer.
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

    // Close the overlapped I/O event handle.
    CloseHandle(sensorContext->Overlapped.hEvent);

    // Release the context structure.
    _AdapterRelease(sensorContext);
    sensorContext = NULL;

    return S_OK;
}

```

## See also

[Plug-in Functions](https://learn.microsoft.com/windows/desktop/SecBioMet/plug-in-functions)

[SensorAdapterAttach](https://learn.microsoft.com/windows/desktop/api/winbio_adapter/nc-winbio_adapter-pibio_sensor_attach_fn)

[WINBIO_PIPELINE](https://learn.microsoft.com/windows/desktop/api/winbio_adapter/ns-winbio_adapter-winbio_pipeline)