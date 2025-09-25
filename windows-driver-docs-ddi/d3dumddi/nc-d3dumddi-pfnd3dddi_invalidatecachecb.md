# PFND3DDDI_INVALIDATECACHECB callback function

## Description

The PFND3DDDI_INVALIDATECACHECB callback function invalidates cache.

## Parameters

### `hDevice`

A handle to the graphics context device.

### `unnamedParam2`

Pointer to a [D3DDDICB_INVALIDATECACHE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddicb_invalidatecache) structure.

## Return value

Returns HRESULT.

## Prototype

```cpp
//Declaration

PFND3DDDI_INVALIDATECACHECB Pfnd3dddiInvalidatecachecb;

// Definition

HRESULT Pfnd3dddiInvalidatecachecb
(
	HANDLE hDevice
	 const D3DDDICB_INVALIDATECACHE *
)
{...}

```