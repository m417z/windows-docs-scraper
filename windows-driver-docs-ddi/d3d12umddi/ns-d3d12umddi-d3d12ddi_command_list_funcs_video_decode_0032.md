# D3D12DDI_COMMAND_LIST_FUNCS_VIDEO_DECODE_0032 structure

## Description

Command list functions for [D3D12DDI_TABLE_TYPE_COMMAND_LIST_VIDEO_DECODE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_table_type).

## Members

### `pfnCloseCommandList`

Close command list.

### `pfnResetCommandList`

Reset command list.

### `pfnDiscardResource`

Discard resource.

### `pfnSetMarker`

Set marker.

### `pfnSetPredication`

Set predication.

### `pfnBeginQuery`

Begin query.

### `pfnEndQuery`

End query.

### `pfnResolveQueryData`

Resolve query data.

### `pfnResourceBarrier`

Resource barrier.

### `pfnDecodeFrame`

Decode frame.

### `pfnSetProtectedResourceSession`

Set protected resource session.

### `pfnWriteBufferImmediate`

Write buffer immediate.

## Remarks

When [PFND3D12DDI_FILLDDITTABLE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_fillddittable) is called for this table type, the *D3D12DDI_HRTTABLE* object must be stored to later call [PFND3D12DDI_SETCOMMANDLISTDDITABLE_CB](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_setcommandlistdditable_cb) during command list creation.