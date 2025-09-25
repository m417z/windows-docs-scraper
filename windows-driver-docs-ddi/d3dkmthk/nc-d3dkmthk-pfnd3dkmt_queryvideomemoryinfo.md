# PFND3DKMT_QUERYVIDEOMEMORYINFO callback function

## Description

The PFND3DKMT_QUERYVIDEOMEMORYINFO callback function queries for video memory info.

## Parameters

### `unnamedParam1`

Pointer to a [D3DKMT_QUERYVIDEOMEMORYINFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_queryvideomemoryinfo) structure.

## Return value

Returns NTSTATUS.

## Prototype

```cpp
//Declaration

PFND3DKMT_QUERYVIDEOMEMORYINFO Pfnd3dkmtQueryvideomemoryinfo;

// Definition

NTSTATUS Pfnd3dkmtQueryvideomemoryinfo
(
	D3DKMT_QUERYVIDEOMEMORYINFO *
)
{...}

```

## Remarks

## See also