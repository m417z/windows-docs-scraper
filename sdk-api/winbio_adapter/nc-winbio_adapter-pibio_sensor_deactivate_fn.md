# PIBIO_SENSOR_DEACTIVATE_FN callback function

## Description

Called by the Windows Biometric Framework to give the Sensor Adapter the chance to perform any work needed to put the sensor component into an idle state.

## Parameters

### `Pipeline` [in, out]

Pointer to the [WINBIO_PIPELINE](https://learn.microsoft.com/windows/desktop/api/winbio_adapter/ns-winbio_adapter-winbio_pipeline) structure associated with the biometric unit performing the operation.

## Return value

If the function succeeds, it returns **S_OK**. If the function fails, it must return one of the following **HRESULT** values to indicate the error.

| Return code | Description |
| --- | --- |
| **E_POINTER** | The *Pipeline* parameter cannot be **NULL**. |

## Remarks

This method is called when the last client using this biometric unit has closed its session handle.

This method executes in the context of the same thread that activated the biometric unit and that processed all other requests for the unit.

When this routine is called, the Engine and Storage adapters are still available.