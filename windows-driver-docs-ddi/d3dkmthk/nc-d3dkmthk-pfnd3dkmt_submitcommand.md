# PFND3DKMT_SUBMITCOMMAND callback function

## Description

The PFND3DKMT_SUBMITCOMMAND callback function is used to submit command buffers on contexts that support graphics processing unit (GPU) virtual addressing.

## Parameters

### `unnamedParam1`

Pointer to a [D3DKMT_SUBMITCOMMAND](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_submitcommand) structure.

## Return value

Returns NTSTATUS.

## Prototype

```cpp
//Declaration

PFND3DKMT_SUBMITCOMMAND Pfnd3dkmtSubmitcommand;

// Definition

NTSTATUS Pfnd3dkmtSubmitcommand
(
	const D3DKMT_SUBMITCOMMAND *
)
{...}

```

## Remarks

## See also