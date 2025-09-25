# PFND3D12DDI_CREATE_PIPELINE_STATE_0021 callback function

## Description

The *pfnCreatePipelineState* callback function creates a pipeline state.

## Parameters

### `unnamedParam1`

*hDevice*

A handle to the display device (graphics context).

### `unnamedParam2`

CreatePipelineState [in]

A value used to create a pipeline state.

### `unnamedParam3`

hRTPipelineState

The handle of the pipeline state for the driver to use when it calls back into the runtime.

### `unnamedParam4`

## Return value

If this callback function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Access this function by using the [D3D12DDI_DEVICE_FUNCS_CORE_0021](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_device_funcs_core_0021) structure.