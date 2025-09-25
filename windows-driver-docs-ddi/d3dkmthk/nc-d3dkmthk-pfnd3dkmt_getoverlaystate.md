# PFND3DKMT_GETOVERLAYSTATE callback function

## Description

Pfnd3dkmtGetoverlaystate retrieves the status about an overlay.

## Parameters

### `unnamedParam1`

Pointer to a [D3DKMT_GETOVERLAYSTATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_getoverlaystate) structure.

## Return value

Returns NTSTATUS.

## Prototype

```cpp
//Declaration

PFND3DKMT_GETOVERLAYSTATE Pfnd3dkmtGetoverlaystate;

// Definition

NTSTATUS Pfnd3dkmtGetoverlaystate
(
	D3DKMT_GETOVERLAYSTATE *
)
{...}

```

## Remarks

## See also