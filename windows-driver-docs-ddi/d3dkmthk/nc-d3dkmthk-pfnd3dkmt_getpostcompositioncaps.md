# PFND3DKMT_GETPOSTCOMPOSITIONCAPS callback function

## Description

Pfnd3dkmtGetpostcompositioncaps retrieves post composition capabilities.

## Parameters

### `unnamedParam1`

Pointer to a [D3DKMT_GET_POST_COMPOSITION_CAPS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_get_post_composition_caps) structure.

## Return value

Returns NTSTATUS.

## Prototype

```cpp
//Declaration

PFND3DKMT_GETPOSTCOMPOSITIONCAPS Pfnd3dkmtGetpostcompositioncaps;

// Definition

NTSTATUS Pfnd3dkmtGetpostcompositioncaps
(
	D3DKMT_GET_POST_COMPOSITION_CAPS *
)
{...}

```

## Remarks

## See also