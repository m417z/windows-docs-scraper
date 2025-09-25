# PIBIO_SENSOR_CANCEL_FN callback function

## Description

Called by the Windows Biometric Framework to cancel all pending sensor operations.

## Parameters

### `Pipeline` [in, out]

Pointer to the [WINBIO_PIPELINE](https://learn.microsoft.com/windows/desktop/api/winbio_adapter/ns-winbio_adapter-winbio_pipeline) structure associated with the biometric unit performing the operation.

## Return value

If the function succeeds, it returns S_OK. If the function fails, it must return one of the following **HRESULT** values to indicate the error.

| Return code | Description |
| --- | --- |
| **E_POINTER** | The *Pipeline* argument cannot be **NULL**. |
| **WINBIO_E_INVALID_DEVICE_STATE** | The **SensorHandle** member of the [WINBIO_PIPELINE](https://learn.microsoft.com/windows/desktop/api/winbio_adapter/ns-winbio_adapter-winbio_pipeline) structure pointed to by the *Pipeline* argument is set to **INVALID_HANDLE_VALUE**. |

## Remarks

Your implementation of this function should not wait for pending operations to complete.

If the sensor has no pending operations when this function is called, your implementation must return S_OK without changing the state of the pipeline.

#### Examples

The following pseudocode shows one possible implementation of this function. The example does not compile. You must adapt it to suit your purpose.

```cpp
//////////////////////////////////////////////////////////////////////////////////////////
//
// SensorAdapterCancel
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
SensorAdapterCancel(
    __inout PWINBIO_PIPELINE Pipeline
    )
{
    HRESULT hr = S_OK;

    // Verify that the Pipeline parameter is not NULL.
    if (!ARGUMENT_PRESENT(Pipeline))
    {
        hr = E_POINTER;
        goto cleanup;
    }

    // Validate the current sensor state.
    if (Pipeline->SensorHandle == INVALID_HANDLE_VALUE)
    {
        return WINBIO_E_INVALID_DEVICE_STATE;
    }

    // Cancel all I/O to the sensor handle.
    if (!CancelIoEx(Pipeline->SensorHandle, NULL))
    {
        hr = _SensorAdapterGetHresultFromWin32(GetLastError());
    }

    return hr;
}

```

## See also

[Plug-in Functions](https://learn.microsoft.com/windows/desktop/SecBioMet/plug-in-functions)