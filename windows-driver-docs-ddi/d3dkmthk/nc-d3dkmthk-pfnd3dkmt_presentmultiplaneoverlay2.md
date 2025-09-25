# PFND3DKMT_PRESENTMULTIPLANEOVERLAY2 callback function

## Description

The PFND3DKMT_PRESENTMULTIPLANEOVERLAY2 callback function copies content from a source multiplane overlay allocation to a destination allocation.

## Parameters

### `unnamedParam1`

Pointer to a [D3DKMT_PRESENT_MULTIPLANE_OVERLAY2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_present_multiplane_overlay2) structure.

## Return value

Returns NTSTATUS.

## Prototype

```cpp
//Declaration

PFND3DKMT_PRESENTMULTIPLANEOVERLAY2 Pfnd3dkmtPresentmultiplaneoverlay2;

// Definition

NTSTATUS Pfnd3dkmtPresentmultiplaneoverlay2
(
	const D3DKMT_PRESENT_MULTIPLANE_OVERLAY2 *
)
{...}

```

## Remarks

## See also