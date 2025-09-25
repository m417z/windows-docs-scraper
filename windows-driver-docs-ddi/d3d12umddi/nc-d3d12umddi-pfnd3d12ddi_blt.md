# PFND3D12DDI_BLT callback function

## Description

The Blt function copies the contents of a source surface to a destination surface.

## Parameters

### `unnamedParam1`

A handle to the driver's data for the command list. The driver uses this region of memory to store internal data structures that are related to its command list.

### `unnamedParam2`

A pointer to a D3D12DDIARG_BLT structure that describes the parameters of the bit-block transfer (bitblt).

## Prototype

```
//Declaration

PFND3D12DDI_BLT Pfnd3d12ddiBlt;

// Definition

VOID Pfnd3d12ddiBlt
(
	D3D12DDI_HCOMMANDLIST Arg1
	 const D3D12DDIARG_BLT *
)
{...}

```

## Remarks

## See also