# PFND3DDDI_SYNCTOKENCB callback function

## Description

The PFND3DDDI_SYNCTOKENCB callback creates a sync token.

## Parameters

### `hDevice`

A handle to the graphics context device.

### `unnamedParam2`

Pointer to a [D3DDDICB_SYNCTOKEN](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddicb_synctoken) structure.

## Return value

Returns HRESULT.

## Prototype

```cpp
//Declaration

PFND3DDDI_SYNCTOKENCB Pfnd3dddiSynctokencb;

// Definition

HRESULT Pfnd3dddiSynctokencb
(
	HANDLE hDevice
	 const D3DDDICB_SYNCTOKEN *
)
{...}

```