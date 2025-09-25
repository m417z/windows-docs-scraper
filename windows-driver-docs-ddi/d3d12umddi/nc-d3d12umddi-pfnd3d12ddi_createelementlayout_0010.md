# PFND3D12DDI_CREATEELEMENTLAYOUT_0010 callback function

## Description

Creates an element layout.

## Parameters

### `unnamedParam1`

A handle to the display device (graphics context).

### `unnamedParam2`

Pointer to a D3D12DDIARG_CREATEELEMENTLAYOUT_0010 structure.

### `unnamedParam3`

An element layout handle.

## Prototype

```cpp
//Declaration

PFND3D12DDI_CREATEELEMENTLAYOUT_0010 Pfnd3d12ddiCreateelementlayout0010;

// Definition

VOID Pfnd3d12ddiCreateelementlayout0010
(
	 D3D12DDI_HDEVICE
	CONST D3D12DDIARG_CREATEELEMENTLAYOUT_0010 *
	 D3D12DDI_HELEMENTLAYOUT
)
{...}

PFND3D12DDI_CREATEELEMENTLAYOUT_0010

```