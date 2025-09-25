# PFND3D12DDI_CLEAR_RENDER_TARGET_VIEW_0003 callback function

## Description

The pfnClearRenderTargetView function clears the specified render-target view by setting it to a constant value.

## Parameters

### `unnamedParam1`

A handle to the driver's data for the command list. The driver uses this region of memory to store internal data structures that are related to its command list.

### `ViewCPUHandle`

Type: D3D12DDI_CPU_DESCRIPTOR_HANDLE

Describes the CPU descriptor handle that represents the start of the heap for the render target to clear.

### `FLOAT`

[4]
A 4-component array that containing the values to fill the unordered-access-view resource with.

### `NumRects`

The number of rectangles in the array that the *pRects* parameter specifies.

### `pRects`

An array of D3D12DDI_RECT structures for the rectangles in the render target view to clear.

## Prototype

```
//Declaration

PFND3D12DDI_CLEAR_RENDER_TARGET_VIEW_0003 Pfnd3d12ddiClearRenderTargetView0003;

// Definition

VOID Pfnd3d12ddiClearRenderTargetView0003
(
	D3D12DDI_HCOMMANDLIST Arg1
	D3D12DDI_CPU_DESCRIPTOR_HANDLE ViewCPUHandle
	 const FLOAT[4]
	UINT NumRects
	 const D3D12DDI_RECT *pRects
)
{...}

```

## Remarks

## See also