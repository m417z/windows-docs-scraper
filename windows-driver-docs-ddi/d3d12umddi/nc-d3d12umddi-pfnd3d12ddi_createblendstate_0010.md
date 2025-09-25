# PFND3D12DDI_CREATEBLENDSTATE_0010 callback function

## Description

Creates a blend state.

## Parameters

### `unnamedParam1`

A handle to the display device (graphics context).

### `unnamedParam2`

Pointer to a D3D12DDI_BLEND_DESC_0010 structure.

### `unnamedParam3`

A blend state handle.

## Prototype

```cpp
//Declaration

PFND3D12DDI_CREATEBLENDSTATE_0010 Pfnd3d12ddiCreateblendstate0010;

// Definition

VOID Pfnd3d12ddiCreateblendstate0010
(
	 D3D12DDI_HDEVICE
	CONST D3D12DDI_BLEND_DESC_0010 *
	 D3D12DDI_HBLENDSTATE
)
{...}

PFND3D12DDI_CREATEBLENDSTATE_0010

```