# PFND3D12DDI_CREATEELEMENTLAYOUT_0003 callback function

## Description

Creates an element layout.

## Parameters

### `unnamedParam1`

A handle to the display device (graphics context).

### `unnamedParam2`

Pointer to a D3D12DDIARG_CREATEELEMENTLAYOUT structure.

### `unnamedParam3`

An element layout handle.

## Prototype

```cpp
//Declaration

PFND3D12DDI_CREATEELEMENTLAYOUT_0003 Pfnd3d12ddiCreateelementlayout0003;

// Definition

VOID Pfnd3d12ddiCreateelementlayout0003
(
	 D3D12DDI_HDEVICE
	CONST D3D12DDIARG_CREATEELEMENTLAYOUT *
	 D3D12DDI_HELEMENTLAYOUT
)
{...}

PFND3D12DDI_CREATEELEMENTLAYOUT_0003

```