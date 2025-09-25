# PFND3DKMT_CHECKMULTIPLANEOVERLAYSUPPORT2 callback function

> [!NOTE] This function has been replaced by [PFND3DKMT_CHECKMULTIPLANEOVERLAYSUPPORT3](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nc-d3dkmthk-pfnd3dkmt_checkmultiplaneoverlaysupport3).

## Description

The PFND3DKMT_CHECKMULTIPLANEOVERLAYSUPPORT2 callback function checks the details of hardware support for multiplane overlays.

## Parameters

### `unnamedParam1` [in, out]

Pointer to a [D3DKMT_CHECKMULTIPLANEOVERLAYSUPPORT2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_checkmultiplaneoverlaysupport2) structure.

## Return value

Returns NTSTATUS.

## Prototype

```cpp
//Declaration

PFND3DKMT_CHECKMULTIPLANEOVERLAYSUPPORT2 Pfnd3dkmtCheckmultiplaneoverlaysupport2;

// Definition

NTSTATUS Pfnd3dkmtCheckmultiplaneoverlaysupport2
(
	D3DKMT_CHECKMULTIPLANEOVERLAYSUPPORT2 *
)
{...}

```