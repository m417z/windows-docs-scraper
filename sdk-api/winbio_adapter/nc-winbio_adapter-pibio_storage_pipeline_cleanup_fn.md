# PIBIO_STORAGE_PIPELINE_CLEANUP_FN callback function

## Description

Called by the Windows Biometric Framework to give the Storage Adapter the chance to perform any cleanup in preparation for closing the template database.

## Parameters

### `Pipeline` [in, out]

Pointer to the [WINBIO_PIPELINE](https://learn.microsoft.com/windows/desktop/api/winbio_adapter/ns-winbio_adapter-winbio_pipeline) structure associated with the biometric unit performing the operation.

## Return value

If the function succeeds, it returns **S_OK**. If the function fails, it must return one of the following **HRESULT** values to indicate the error.

| Return code | Description |
| --- | --- |
| **E_POINTER** | The *Pipeline* parameter cannot be **NULL**. |

## Remarks

This method is called once, when a biometric unit is being torn down.

The Storage Adapter should return **S_OK** if it doesn’t need to perform any cleanup at this point.

This method executes in the context of an arbitrary RPC server thread.