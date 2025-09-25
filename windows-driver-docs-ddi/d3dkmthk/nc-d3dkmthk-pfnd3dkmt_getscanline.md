# PFND3DKMT_GETSCANLINE callback function

## Description

Pfnd3dkmtGetscanline determines whether the given video present source of a video present network (VidPN) is in vertical blanking mode and retrieves the current scan line.

## Parameters

### `unnamedParam1`

Pointer to a [D3DKMT_GETSCANLINE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_getscanline) structure.

## Return value

Returns NTSTATUS.

## Prototype

```cpp
//Declaration

PFND3DKMT_GETSCANLINE Pfnd3dkmtGetscanline;

// Definition

NTSTATUS Pfnd3dkmtGetscanline
(
	D3DKMT_GETSCANLINE *
)
{...}

```

## Remarks

## See also