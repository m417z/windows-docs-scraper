# PFND3DKMT_PRESENTMULTIPLANEOVERLAY callback function

## Description

The PFND3DKMT_PRESENTMULTIPLANEOVERLAY callback function copies content from a source multiplane overlay allocation to a destination allocation.

## Parameters

### `unnamedParam1`

Pointer to a [D3DKMT_PRESENT_MULTIPLANE_OVERLAY](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-d3dkmt_present_multiplane_overlay) structure.

## Return value

Returns NTSTATUS.

## Prototype

```cpp
//Declaration

PFND3DKMT_PRESENTMULTIPLANEOVERLAY Pfnd3dkmtPresentmultiplaneoverlay;

// Definition

NTSTATUS Pfnd3dkmtPresentmultiplaneoverlay
(
	const D3DKMT_PRESENT_MULTIPLANE_OVERLAY *
)
{...}

```

## Remarks

## See also