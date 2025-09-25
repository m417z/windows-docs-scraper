# PFND3DKMT_PRESENTMULTIPLANEOVERLAY3 callback function

## Description

The PFND3DKMT_PRESENTMULTIPLANEOVERLAY3 callback function copies content from a source multiplane overlay allocation to a destination allocation.

## Parameters

### `unnamedParam1`

Pointer to a [[D3DKMT_PRESENT_MULTIPLANE_OVERLAY3](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_present_multiplane_overlay3)]() structure.

## Return value

Returns NTSTATUS.

## Prototype

```cpp
//Declaration

PFND3DKMT_PRESENTMULTIPLANEOVERLAY3 Pfnd3dkmtPresentmultiplaneoverlay3;

// Definition

NTSTATUS Pfnd3dkmtPresentmultiplaneoverlay3
(
	const D3DKMT_PRESENT_MULTIPLANE_OVERLAY3 *
)
{...}

```

## Remarks

## See also