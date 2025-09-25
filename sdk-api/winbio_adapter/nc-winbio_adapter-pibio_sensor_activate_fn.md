# PIBIO_SENSOR_ACTIVATE_FN callback function

## Description

Called by the Windows Biometric Framework to give the Sensor Adapter the chance to perform any work needed to bring the sensor component out of an idle state.

## Parameters

### `Pipeline` [in, out]

Pointer to the [WINBIO_PIPELINE](https://learn.microsoft.com/windows/desktop/api/winbio_adapter/ns-winbio_adapter-winbio_pipeline) structure associated with the biometric unit performing the operation.

## Return value

If the function succeeds, it returns **S_OK**. If the function fails, it must return one of the following **HRESULT** values to indicate the error.

| Return code | Description |
| --- | --- |
| **E_POINTER** | The *Pipeline* parameter cannot be **NULL**. |

## Remarks

This method is called when the first client session opens a handle to an inactive biometric unit.

Both the Engine and Storage adapters have been activated when this method is called.

Returning any **HRESULT** other than **S_OK** will cause the Windows Biometric Framework to log the error and abort the activation of the biometric unit.

This method executes in the context of the sensor control thread that will process all other requests for the unit, including deactivation.