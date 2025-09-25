# PFND3DKMT_OUTPUTDUPLGETFRAMEINFO callback function

## Description

The PFND3DKMT_OUTPUTDUPLGETFRAMEINFO callback function gets output duplicate frame info.

## Parameters

### `unnamedParam1`

Pointer to a [D3DKMT_OUTPUTDUPL_GET_FRAMEINFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_outputdupl_get_frameinfo) structure.

## Return value

Returns NTSTATUS.

## Prototype

```cpp
//Declaration

PFND3DKMT_OUTPUTDUPLGETFRAMEINFO Pfnd3dkmtOutputduplgetframeinfo;

// Definition

NTSTATUS Pfnd3dkmtOutputduplgetframeinfo
(
	D3DKMT_OUTPUTDUPL_GET_FRAMEINFO *
)
{...}

```

## Remarks

## See also