# PIBIO_SENSOR_PIPELINE_CLEANUP_FN callback function

## Description

Called by the Windows Biometric Framework to give the Sensor Adapter the chance to perform any cleanup in that requires help from the Engine or Storage adapter components.

## Parameters

### `Pipeline` [in, out]

Pointer to the [WINBIO_PIPELINE](https://learn.microsoft.com/windows/desktop/api/winbio_adapter/ns-winbio_adapter-winbio_pipeline) structure associated with the biometric unit performing the operation.

## Return value

If the function succeeds, it returns **S_OK**. If the function fails, it must return one of the following **HRESULT** values to indicate the error.

| Return code | Description |
| --- | --- |
| **E_POINTER** | The *Pipeline* parameter cannot be **NULL**. |

## Remarks

The Sensor Adapter should return **S_OK** if it doesn’t need to perform any cleanup at this point.

When this routine is called, the Engine and Storage adapters are still available.

This method executes in the context of an arbitrary RPC server thread.