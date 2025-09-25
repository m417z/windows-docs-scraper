# PFND3D12DDI_CALCPRIVATEVIDEOMOTIONVECTORHEAPSIZE_0060 callback function

## Description

Calculates the video motion vector heap size.

## Parameters

### `hDrvDevice`

A handle to the display device (graphics context).

### `pArgs`

Pointer to a [D3D12DDIARG_CREATE_VIDEO_MOTION_VECTOR_HEAP_0060](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddiarg_create_video_motion_vector_heap_0060) structure.

## Return value

Returns SIZE_T.

## Prototype

```
//Declaration

PFND3D12DDI_CALCPRIVATEVIDEOMOTIONVECTORHEAPSIZE_0060 Pfnd3d12ddiCalcprivatevideomotionvectorheapsize0060;

// Definition

SIZE_T Pfnd3d12ddiCalcprivatevideomotionvectorheapsize0060
(
	D3D12DDI_HDEVICE hDrvDevice
	 const D3D12DDIARG_CREATE_VIDEO_MOTION_VECTOR_HEAP_0060 *pArgs
)
{...}

```

## Remarks

## See also