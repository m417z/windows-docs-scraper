# PFND3DKMT_GETSHAREDRESOURCEADAPTERLUID callback function

## Description

Pfnd3dkmtGetsharedresourceadapterluid maps a shared resource to a locally unique identifier (LUID) that identifies the graphics adapter that the resource was created on.

## Parameters

### `unnamedParam1`

Pointer to a [D3DKMT_GETSHAREDRESOURCEADAPTERLUID](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_getsharedresourceadapterluid) structure.

## Return value

Returns NTSTATUS.

## Prototype

```cpp
//Declaration

PFND3DKMT_GETSHAREDRESOURCEADAPTERLUID Pfnd3dkmtGetsharedresourceadapterluid;

// Definition

NTSTATUS Pfnd3dkmtGetsharedresourceadapterluid
(
	D3DKMT_GETSHAREDRESOURCEADAPTERLUID *
)
{...}

```

## Remarks

## See also