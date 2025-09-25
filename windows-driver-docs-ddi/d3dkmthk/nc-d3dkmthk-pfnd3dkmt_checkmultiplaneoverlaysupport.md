# PFND3DKMT_CHECKMULTIPLANEOVERLAYSUPPORT callback function

> [!NOTE] This function has been replaced by [PFND3DKMT_CHECKMULTIPLANEOVERLAYSUPPORT3](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nc-d3dkmthk-pfnd3dkmt_checkmultiplaneoverlaysupport3).

## Description

The PFND3DKMT_CHECKMULTIPLANEOVERLAYSUPPORT callback function checks the details of hardware support for multiplane overlays.

## Parameters

### `unnamedParam1` [in, out]

Pointer to a [D3DKMT_CHECKMULTIPLANEOVERLAYSUPPORT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_checkmultiplaneoverlaysupport) structure.

## Return value

Returns NTSTATUS.

## Prototype

```cpp
//Declaration

PFND3DKMT_CHECKMULTIPLANEOVERLAYSUPPORT Pfnd3dkmtCheckmultiplaneoverlaysupport;

// Definition

NTSTATUS Pfnd3dkmtCheckmultiplaneoverlaysupport
(
	D3DKMT_CHECKMULTIPLANEOVERLAYSUPPORT *
)
{...}

```