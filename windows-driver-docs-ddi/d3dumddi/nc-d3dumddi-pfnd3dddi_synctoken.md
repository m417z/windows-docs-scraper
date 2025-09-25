# PFND3DDDI_SYNCTOKEN callback function

## Description

The PFND3DDDI_SYNCTOKEN callback creates a sync token.

## Parameters

### `hDevice`

A handle to the graphics context device.

### `unnamedParam2`

Pointer to a [D3DDDIARG_SYNCTOKEN](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_synctoken) structure.

## Prototype

```cpp
//Declaration

PFND3DDDI_SYNCTOKEN Pfnd3dddiSynctoken;

// Definition

VOID Pfnd3dddiSynctoken
(
	HANDLE hDevice
	 const D3DDDIARG_SYNCTOKEN *
)
{...}

```