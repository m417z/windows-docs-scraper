# PFND3D12DDI_CREATE_PIPELINE_STATE_0075 callback function

## Description

**PFND3D12DDI_CREATE_PIPELINE_STATE_0075** is used to create a pipeline state.

## Parameters

### `unnamedParam1`

A handle to the display device (graphics context).

### `unnamedParam2`

Pointer to a [**D3D12DDIARG_CREATE_PIPELINE_STATE_0075**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddiarg_create_pipeline_state_0075) structure with arguments used to create a pipeline state.

### `unnamedParam3`

Handle to the pipeline state.

### `unnamedParam4`

Handle to the pipeline state for the driver to use when it calls back into the runtime.

## Return value

Returns STATUS_SUCCESS if completed successfully.

## See also

[**D3D12DDIARG_CREATE_PIPELINE_STATE_0075**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddiarg_create_pipeline_state_0075)