## Description

The **D3D12DDI_COMMAND_LIST_FUNCS_VIDEO_DECODE_0088** structure contains pointers to command list functions for video decode, version D3D12DDI_FEATURE_VERSION_VIDEO_0088.

## Members

### `pfnCloseCommandList`

Pointer to a **PFND3D12DDI_CLOSECOMMANDLIST** function that closes the command list.

### `pfnResetCommandList`

Pointer to a [**PFND3D12DDI_RESETCOMMANDLIST_0040**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_resetcommandlist_0040) function that resets the command list.

### `pfnDiscardResource`

Pointer to a **PFND3D12DDI_DISCARD_RESOURCE_0003** function that discards a resource.

### `pfnSetMarker`

Pointer to a **PFND3D12DDI_SET_MARKER** function that sets a marker.

### `pfnSetPredication`

Pointer to a **PFND3D12DDI_SET_PREDICATION** function that sets predication.

### `pfnBeginQuery`

Pointer to a **PFND3D12DDI_BEGIN_END_QUERY_0003** function that begins a query.

### `pfnEndQuery`

Pointer to a **PFND3D12DDI_BEGIN_END_QUERY_0003** function that ends a query.

### `pfnResolveQueryData`

Pointer to a **PFND3D12DDI_RESOLVE_QUERY_DATA** function that resolves query data.

### `pfnResourceBarrier`

Pointer to a **PFND3D12DDI_RESOURCEBARRIER_0022** function.

### `pfnDecodeFrame`

Pointer to a **PFND3D12DDI_VIDEO_DECODE_FRAME_0041_1** function.

### `pfnSetProtectedResourceSession`

Pointer to a **PFND3D12DDI_SETPROTECTEDRESOURCESESSION_0030** function.

### `pfnWriteBufferImmediate`

Pointer to a **PFND3D12DDI_WRITEBUFFERIMMEDIATE_0032** function.

### `pfnInitializeVideoExtensionCommand`

Pointer to a **PFND3D12DDI_INITIALIZE_VIDEO_EXTENSION_COMMAND_0063** function.

### `pfnExecuteVideoExtensionCommand`

Pointer to **PFND3D12DDI_EXECUTE_VIDEO_EXTENSION_COMMAND_0063** function.

### `pfnBarrier`

Pointer to a **PFND3D12DDI_BARRIER_0088** function.

## Remarks

## See also