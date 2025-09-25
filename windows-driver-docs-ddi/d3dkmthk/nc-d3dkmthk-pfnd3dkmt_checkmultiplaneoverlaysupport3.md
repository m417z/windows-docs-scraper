# PFND3DKMT_CHECKMULTIPLANEOVERLAYSUPPORT3 callback function

## Description

The PFND3DKMT_CHECKMULTIPLANEOVERLAYSUPPORT3 callback function checks the details of hardware support for multiplane overlays.

## Parameters

### `unnamedParam1` [in, out]

Pointer to a [D3DKMT_CHECKMULTIPLANEOVERLAYSUPPORT3](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_checkmultiplaneoverlaysupport3) structure.

## Return value

Returns NTSTATUS.

## Prototype

```cpp
//Declaration

PFND3DKMT_CHECKMULTIPLANEOVERLAYSUPPORT3 Pfnd3dkmtCheckmultiplaneoverlaysupport3;

// Definition

NTSTATUS Pfnd3dkmtCheckmultiplaneoverlaysupport3
(
	D3DKMT_CHECKMULTIPLANEOVERLAYSUPPORT3 *
)
{...}

```