# PFND3DKMT_ESCAPE callback function

## Description

The Pfnd3dkmtEscape callback function shares info with the kernel mode display driver.

## Parameters

### `unnamedParam1`

Pointer to a [D3DKMT_ESCAPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_escape) structure.

## Return value

Returns NTSTATUS.

## Prototype

```cpp
//Declaration

PFND3DKMT_ESCAPE Pfnd3dkmtEscape;

// Definition

NTSTATUS Pfnd3dkmtEscape
(
	const D3DKMT_ESCAPE *
)
{...}

```

## Remarks

## See also