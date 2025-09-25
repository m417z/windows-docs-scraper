# PFND3DKMT_CREATEOVERLAY callback function

## Description

The PFND3DKMT_CREATEOVERLAY callback function enables the overlay hardware if the hardware is capable.

## Parameters

### `unnamedParam1` [in, out]

Pointer to a [D3DKMT_CREATEOVERLAY](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_createoverlay) structure.

## Return value

Returns NTSTATUS.

## Prototype

```cpp
//Declaration

PFND3DKMT_CREATEOVERLAY Pfnd3dkmtCreateoverlay;

// Definition

NTSTATUS Pfnd3dkmtCreateoverlay
(
	D3DKMT_CREATEOVERLAY *
)
{...}

```