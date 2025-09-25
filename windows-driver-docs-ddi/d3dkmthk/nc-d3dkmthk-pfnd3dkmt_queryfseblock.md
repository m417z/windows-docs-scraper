# PFND3DKMT_QUERYFSEBLOCK callback function

## Description

The PFND3DKMT_QUERYFSEBLOCK callback function queries FSE blocks.

## Parameters

### `unnamedParam1`

Pointer to a [D3DKMT_QUERYFSEBLOCK](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_queryfseblock) structure.

## Return value

Returns NTSTATUS.

## Prototype

```cpp
//Declaration

PFND3DKMT_QUERYFSEBLOCK Pfnd3dkmtQueryfseblock;

// Definition

NTSTATUS Pfnd3dkmtQueryfseblock
(
	D3DKMT_QUERYFSEBLOCK *
)
{...}

```

## Remarks

## See also