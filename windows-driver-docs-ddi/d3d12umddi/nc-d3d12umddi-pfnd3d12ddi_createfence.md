# PFND3D12DDI_CREATEFENCE callback function

## Description

Creates a fence.

## Parameters

### `unnamedParam1`

A handle to the display device (graphics context).

### `unnamedParam2`

A fence handle.

### `unnamedParam3`

Pointer to a D3D12DDIARG_CREATE_FENCE structure.

## Return value

Returns HRESULT.

## Prototype

```cpp
//Declaration

PFND3D12DDI_CREATEFENCE Pfnd3d12ddiCreatefence;

// Definition

HRESULT Pfnd3d12ddiCreatefence
(
	 D3D12DDI_HDEVICE
	 D3D12DDI_HFENCE
	CONST D3D12DDIARG_CREATE_FENCE *
)
{...}

PFND3D12DDI_CREATEFENCE

```