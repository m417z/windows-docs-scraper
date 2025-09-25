# PFND3D12DDI_OFFERRESOURCES callback function

## Description

Implemented by the client driver to offer resources.

## Parameters

### `unnamedParam1`

A handle to the display device (graphics context).

### `unnamedParam2`

Pointer to a D3D12DDIARG_OFFERRESOURCES structure.

## Return value

Returns HRESULT.

## Prototype

```cpp
//Declaration

PFND3D12DDI_OFFERRESOURCES Pfnd3d12ddiOfferresources;

// Definition

HRESULT Pfnd3d12ddiOfferresources
(
	 D3D12DDI_HDEVICE
	CONST D3D12DDIARG_OFFERRESOURCES *
)
{...}

PFND3D12DDI_OFFERRESOURCES

```

## Remarks

## See also