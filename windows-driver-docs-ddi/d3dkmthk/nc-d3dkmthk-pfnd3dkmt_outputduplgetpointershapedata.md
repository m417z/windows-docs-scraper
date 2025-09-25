# PFND3DKMT_OUTPUTDUPLGETPOINTERSHAPEDATA callback function

## Description

The PFND3DKMT_OUTPUTDUPLGETPOINTERSHAPEDATA callback function gets output duplicate pointer shape data.

## Parameters

### `unnamedParam1`

Pointer to a [D3DKMT_OUTPUTDUPL_GET_POINTER_SHAPE_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_outputdupl_get_pointer_shape_data) structure.

## Return value

Returns NTSTATUS.

## Prototype

```cpp
//Declaration

PFND3DKMT_OUTPUTDUPLGETPOINTERSHAPEDATA Pfnd3dkmtOutputduplgetpointershapedata;

// Definition

NTSTATUS Pfnd3dkmtOutputduplgetpointershapedata
(
	D3DKMT_OUTPUTDUPL_GET_POINTER_SHAPE_DATA *
)
{...}

```

## Remarks

## See also