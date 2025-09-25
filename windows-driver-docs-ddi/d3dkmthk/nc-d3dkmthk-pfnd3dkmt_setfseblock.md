# PFND3DKMT_SETFSEBLOCK callback function

## Description

The PFND3DKMT_SETFSEBLOCK callback function sets FSE block.

## Parameters

### `unnamedParam1`

Pointer to a [D3DKMT_SETFSEBLOCK](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_setfseblock) structure.

## Return value

Returns NTSTATUS.

## Prototype

```cpp
//Declaration

PFND3DKMT_SETFSEBLOCK Pfnd3dkmtSetfseblock;

// Definition

NTSTATUS Pfnd3dkmtSetfseblock
(
	const D3DKMT_SETFSEBLOCK *
)
{...}

```

## Remarks

## See also