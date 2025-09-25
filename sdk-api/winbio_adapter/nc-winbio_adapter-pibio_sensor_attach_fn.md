# PIBIO_SENSOR_ATTACH_FN callback function

## Description

Called by the Windows Biometric Framework when a sensor adapter is added to the processing pipeline of the biometric unit. The purpose of this function is to perform any initialization required for later biometric operations.

## Parameters

### `Pipeline` [in, out]

Pointer to the [WINBIO_PIPELINE](https://learn.microsoft.com/windows/desktop/api/winbio_adapter/ns-winbio_adapter-winbio_pipeline) structure associated with the biometric unit performing the operation.

## Return value

If the function succeeds, it returns S_OK. If the function fails, it must return one of the following **HRESULT** values to indicate the error.

| Return code | Description |
| --- | --- |
| **E_POINTER** | The *Pipeline* argument cannot be **NULL**. |
| **E_OUTOFMEMORY** | The operation could not be completed because of insufficient memory. |
| **WINBIO_E_INVALID_DEVICE_STATE** | The **SensorContext** member of the [WINBIO_PIPELINE](https://learn.microsoft.com/windows/desktop/api/winbio_adapter/ns-winbio_adapter-winbio_pipeline) structure pointed to by the *Pipeline* argument is not **NULL**. |

## Remarks

This function is called before the engine and storage adapters have been initialized for the biometric unit. Therefore, this function must not call any functions referenced by the [WINBIO_ENGINE_INTERFACE](https://learn.microsoft.com/windows/win32/api/winbio_adapter/ns-winbio_adapter-winbio_storage_interface) or the [WINBIO_STORAGE_INTERFACE](https://learn.microsoft.com/windows/desktop/api/winbio_adapter/ns-winbio_adapter-winbio_storage_interface) structure pointed to by the **EngineInterface** and **StorageInterface** members of the pipeline object.

Because the **SensorHandle** member of the [WINBIO_PIPELINE](https://learn.microsoft.com/windows/desktop/api/winbio_adapter/ns-winbio_adapter-winbio_pipeline) structure will contain a valid handle before this method is called, your implementation of *SensorAdapterAttach* can use the handle to access the sensor device if necessary.

When implementing this function, you must allocate and manage any resources required by the adapter and attach these to the biometric unit pipeline. To do this, allocate a private **WINBIO_SENSOR_CONTEXT** structure on the heap, initialize it, and set its address in the **SensorContext** member of the pipeline object.

If there is an error during the creation and initialization of engine adapter resources used by this function, you must perform any required cleanup before returning.

If the **SensorContext** field is not **NULL** when this function is called, the pipeline was not properly reset by a prior call to [SensorAdapterDetach](https://learn.microsoft.com/windows/desktop/api/winbio_adapter/nc-winbio_adapter-pibio_sensor_detach_fn) and you must return **WINBIO_E_INVALID_DEVICE_STATE** to notify the Windows Biometric Framework of the problem.

#### Examples

The following pseudocode shows one possible implementation of this function. The example does not compile. You must adapt it to suit your purpose.

```cpp
//////////////////////////////////////////////////////////////////////////////////////////
//
// SensorAdapterAttach
//
// Purpose:
//      Performs any initialization required for later biometric operations.
//
// Parameters:
//      Pipeline -  Pointer to a WINBIO_PIPELINE structure associated with
//                  the biometric unit performing the operation.
//
static HRESULT
WINAPI
SensorAdapterAttach(
    __inout PWINBIO_PIPELINE Pipeline
    )
{
    HRESULT hr = S_OK;
    PWINBIO_SENSOR_CONTEXT newContext = NULL;

    // Verify that the Pipeline parameter is not NULL.
    if (!ARGUMENT_PRESENT(Pipeline))
    {
        hr = E_POINTER;
        goto cleanup;
    }

    // Validate the current sensor state.
    if (Pipeline->SensorContext != NULL)
    {
        hr = WINBIO_E_INVALID_DEVICE_STATE;
        goto cleanup;
    }

    // Use a custom function (_AdapterAlloc) to allocate memory for the
    // sensor adapter context.
    newContext = (PWINBIO_SENSOR_CONTEXT)_AdapterAlloc(sizeof(WINBIO_SENSOR_CONTEXT));
    if (newContext == NULL)
    {
        hr = E_OUTOFMEMORY;
        goto cleanup;
    }

    // Create a manual reset event to monitor overlapped I/O.
    newContext->Overlapped.hEvent = CreateEvent(NULL, TRUE, FALSE, NULL);
    if (newContext->Overlapped.hEvent == NULL)
    {
        hr = E_OUTOFMEMORY;
        goto cleanup;
    }

    // Initialize any required context fields. This example assumes that your
    // sensor context points to a capture buffer and an attributes buffer.
    newContext->CaptureBuffer = NULL;
    newContext->CaptureBufferSize = 0;

    newContext->AttributesBuffer = NULL;
    newContext->AttributesBufferSize = sizeof (WINBIO_SENSOR_ATTRIBUTES);

    // Transfer ownership of the new sensor context structure to the
    // pipeline.
    Pipeline->SensorContext = newContext;
    newContext = NULL;

cleanup:

    if (FAILED(hr) && newContext != NULL)
    {
        CloseHandle( newContext->Overlapped.hEvent;
        _AdapterRelease( newContext );
        newContext = NULL;
    }
    return hr;
}

```

## See also

[EngineAdapterAttach](https://learn.microsoft.com/windows/desktop/api/winbio_adapter/nc-winbio_adapter-pibio_engine_attach_fn)

[Plug-in Functions](https://learn.microsoft.com/windows/desktop/SecBioMet/plug-in-functions)

[SensorAdapterDetach](https://learn.microsoft.com/windows/desktop/api/winbio_adapter/nc-winbio_adapter-pibio_sensor_detach_fn)

[StorageAdapterAttach](https://learn.microsoft.com/windows/desktop/api/winbio_adapter/nc-winbio_adapter-pibio_storage_attach_fn)

[WINBIO_PIPELINE](https://learn.microsoft.com/windows/desktop/api/winbio_adapter/ns-winbio_adapter-winbio_pipeline)