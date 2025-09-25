# PFND3D12DDI_CLEAR_DEPTH_STENCIL_VIEW_0003 callback function

## Description

The pfnClearDepthStencilView function clears the specified currently bound depth-stencil view.

## Parameters

### `unnamedParam1`

A handle to the driver's data for the command list. The driver uses this region of memory to store internal data structures that are related to its command list.

### `ViewCPUHandle`

Type: D3D12DDI_CPU_DESCRIPTOR_HANDLE

Describes the CPU descriptor handle that represents the start of the heap for the depth stencil view to clear.

### `unnamedParam3`

A value that specifies which parts of the buffer to affect.

### `unnamedParam4`

An unsigned 8-bit integer value to set the stencil to.

### `unnamedParam5`

### `NumRects`

The number of rectangles in the array that the *pRects* parameter specifies.

### `pRects`

An array of D3D12DDI_RECT structures for the rectangles in the resource view to clear.

## Prototype

```
//Declaration

PFND3D12DDI_CLEAR_DEPTH_STENCIL_VIEW_0003 Pfnd3d12ddiClearDepthStencilView0003;

// Definition

VOID Pfnd3d12ddiClearDepthStencilView0003
(
	D3D12DDI_HCOMMANDLIST Arg1
	D3D12DDI_CPU_DESCRIPTOR_HANDLE ViewCPUHandle
	UINT Arg2
	FLOAT Arg3
	UINT8 Arg4
	UINT NumRects
	 const D3D12DDI_RECT *pRects
)
{...}

```

## Remarks

## See also