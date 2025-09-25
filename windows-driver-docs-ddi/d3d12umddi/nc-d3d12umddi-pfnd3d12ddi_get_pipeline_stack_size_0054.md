# PFND3D12DDI_GET_PIPELINE_STACK_SIZE_0054 callback function

## Description

GetPipelineStackSize retrieves the current pipeline stack size.

## Parameters

### `unnamedParam1`

A handle to the state object.

## Return value

Returns UINT that represents the current pipeline stack size in bytes. If called on non-executable state objects (e.g. collections), the return value is 0.

## Prototype

```cpp
//Declaration

PFND3D12DDI_GET_PIPELINE_STACK_SIZE_0054 Pfnd3d12ddiGetPipelineStackSize0054;

// Definition

UINT Pfnd3d12ddiGetPipelineStackSize0054
(
	D3D12DDI_HSTATEOBJECT_0054 Arg1
)
{...}

```

## Remarks

GetPipelineStackSize and [SetPipelineStackSize](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_set_pipeline_stack_size_0054) are not re-entrant. This means that if calling either or both from separate threads, the app must synchronize on its own.

## See also