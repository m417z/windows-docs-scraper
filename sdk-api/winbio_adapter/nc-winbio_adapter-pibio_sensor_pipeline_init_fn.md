# PIBIO_SENSOR_PIPELINE_INIT_FN callback function

## Description

Called by the Windows Biometric Framework to give the Sensor Adapter the chance to perform any initialization that remains incomplete, and which requires help from the Engine or Storage adapter components.

## Parameters

### `Pipeline` [in, out]

Pointer to the [WINBIO_PIPELINE](https://learn.microsoft.com/windows/desktop/api/winbio_adapter/ns-winbio_adapter-winbio_pipeline) structure associated with the biometric unit performing the operation.

## Return value

If the function succeeds, it returns **S_OK**. If the function fails, it must return one of the following **HRESULT** values to indicate the error.

| Return code | Description |
| --- | --- |
| **E_some_error** | Any error code will cause the Biometric Service to log the error and abort the configuration of the biometric unit. |

## Remarks

The Sensor Adapter should return **S_OK** if it doesn’t need to perform any initialization at this point.

When this routine is called, the [EngineAdapterAttach](https://learn.microsoft.com/windows/desktop/api/winbio_adapter/nc-winbio_adapter-pibio_engine_attach_fn), [StorageAdapterAttach](https://learn.microsoft.com/windows/desktop/api/winbio_adapter/nc-winbio_adapter-pibio_storage_attach_fn), [EngineAdapterPipelineInit](https://learn.microsoft.com/windows/desktop/api/winbio_adapter/nc-winbio_adapter-pibio_engine_pipeline_init_fn), and [StorageAdapterPipelineInit](https://learn.microsoft.com/windows/desktop/api/winbio_adapter/nc-winbio_adapter-pibio_storage_pipeline_init_fn) routines have completed normally.

This method executes in the context of an arbitrary RPC server thread.