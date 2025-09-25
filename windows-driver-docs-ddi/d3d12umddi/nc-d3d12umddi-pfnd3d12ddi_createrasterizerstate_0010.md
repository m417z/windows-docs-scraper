# PFND3D12DDI_CREATERASTERIZERSTATE_0010 callback function

## Description

Creates a rasterizer state.

## Parameters

### `unnamedParam1`

A handle to the display device (graphics context).

### `unnamedParam2`

Pointer to a D3D12DDI_RASTERIZER_DESC_0010 structure.

### `unnamedParam3`

A handle to a rasterizer state.

## Prototype

```cpp
//Declaration

PFND3D12DDI_CREATERASTERIZERSTATE_0010 Pfnd3d12ddiCreaterasterizerstate0010;

// Definition

VOID Pfnd3d12ddiCreaterasterizerstate0010
(
	 D3D12DDI_HDEVICE
	CONST D3D12DDI_RASTERIZER_DESC_0010 *
	 D3D12DDI_HRASTERIZERSTATE
)
{...}

PFND3D12DDI_CREATERASTERIZERSTATE_0010

```