# PFND3DKMT_GETMULTIPLANEOVERLAYCAPS callback function

## Description

Pfnd3dkmtGetmultiplaneoverlaycaps retrieves multiplane overlay capabilities.

## Parameters

### `unnamedParam1`

Pointer to a [D3DKMT_GET_MULTIPLANE_OVERLAY_CAPS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_get_multiplane_overlay_caps) structure.

## Return value

Returns NTSTATUS.

## Prototype

```cpp
//Declaration

PFND3DKMT_GETMULTIPLANEOVERLAYCAPS Pfnd3dkmtGetmultiplaneoverlaycaps;

// Definition

NTSTATUS Pfnd3dkmtGetmultiplaneoverlaycaps
(
	D3DKMT_GET_MULTIPLANE_OVERLAY_CAPS *
)
{...}

```

## Remarks

## See also