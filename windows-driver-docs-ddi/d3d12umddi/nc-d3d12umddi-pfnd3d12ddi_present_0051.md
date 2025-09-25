# PFND3D12DDI_PRESENT_0051 callback function

## Description

The PFND3D12DDI_PRESENT_0051 callback function copies content from source allocations to a primary surface (and sometimes to off-screen system memory allocations).

## Parameters

### `unnamedParam1`

A handle to the driver's data for the command list.

### `unnamedParam2`

A handle the driver's data for the command queue.

### `unnamedParam3`

Pointer to a [D3D12DDIARG_PRESENT_0001](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddiarg_present_0001) structure that contains arguments.

### `unnamedParam4`

Pointer to a [D3D12DDI_PRESENT_0051](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_present_0051) structure that contains arguments for this callback.

### `unnamedParam5`

Pointer to a [D3D12DDI_PRESENT_CONTEXTS_0051](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_present_contexts_0051) structure.

### `unnamedParam6`

Pointer to a [D3D12DDI_PRESENT_HWQUEUES_0051](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_present_hwqueues_0051) structure.

## Prototype

```cpp
//Declaration

PFND3D12DDI_PRESENT_0051 Pfnd3d12ddiPresent0051;

// Definition

VOID Pfnd3d12ddiPresent0051
(
	D3D12DDI_HCOMMANDLIST Arg1
	D3D12DDI_HCOMMANDQUEUE Arg2
	CONST D3D12DDIARG_PRESENT_0001 *
	D3D12DDI_PRESENT_0051 *
	D3D12DDI_PRESENT_CONTEXTS_0051 *
	D3D12DDI_PRESENT_HWQUEUES_0051 *
)
{...}

```

## Remarks

The PFND3D12DDI_PRESENT_0051 callback function split the output arguments into ones that are relevant for the command queue involved. For software scheduled command queues, the driver provides contexts. For hardware scheduled command queues, the driver provides hardware queues.

## See also