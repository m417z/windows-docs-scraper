# PFND3DKMT_FLIPOVERLAY callback function

## Description

The Pfnd3dkmtFlipoverlay callback function displays a new allocation by using the specified overlay.

## Parameters

### `unnamedParam1`

Pointer to a [D3DKMT_FLIPOVERLAY](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_flipoverlay) structure.

## Return value

Returns NTSTATUS.

## Prototype

```cpp
//Declaration

PFND3DKMT_FLIPOVERLAY Pfnd3dkmtFlipoverlay;

// Definition

NTSTATUS Pfnd3dkmtFlipoverlay
(
	const D3DKMT_FLIPOVERLAY *
)
{...}

```

## Remarks

## See also