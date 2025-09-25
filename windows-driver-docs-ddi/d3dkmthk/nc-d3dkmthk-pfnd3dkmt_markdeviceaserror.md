# PFND3DKMT_MARKDEVICEASERROR callback function

## Description

Pfnd3dkmtMarkdeviceaserror marks a device as error.

## Parameters

### `unnamedParam1`

Pointer to a [D3DKMT_MARKDEVICEASERROR](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_markdeviceaserror) structure.

## Return value

Returns NTSTATUS.

## Prototype

```cpp
//Declaration

PFND3DKMT_MARKDEVICEASERROR Pfnd3dkmtMarkdeviceaserror;

// Definition

NTSTATUS Pfnd3dkmtMarkdeviceaserror
(
	D3DKMT_MARKDEVICEASERROR *
)
{...}

```

## Remarks

## See also