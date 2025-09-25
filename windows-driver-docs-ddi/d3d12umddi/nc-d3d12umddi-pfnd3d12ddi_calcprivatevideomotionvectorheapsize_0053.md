# PFND3D12DDI_CALCPRIVATEVIDEOMOTIONVECTORHEAPSIZE_0053 callback function

## Description

Calculates the video motion vector heap size.

## Parameters

### `hDrvDevice`

A handle to the display device (graphics context).

### `pArgs`

Pointer to a [D3D12DDIARG_CREATE_VIDEO_MOTION_VECTOR_HEAP_0053](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddiarg_create_video_motion_vector_heap_0053) structure.

## Return value

Returns SIZE_T.

## Prototype

```cpp
//Declaration

PFND3D12DDI_CALCPRIVATEVIDEOMOTIONVECTORHEAPSIZE_0053 Pfnd3d12ddiCalcprivatevideomotionvectorheapsize0053;

// Definition

SIZE_T Pfnd3d12ddiCalcprivatevideomotionvectorheapsize0053
(
	D3D12DDI_HDEVICE hDrvDevice
	CONST D3D12DDIARG_CREATE_VIDEO_MOTION_VECTOR_HEAP_0053 *pArgs
)
{...}

```

## Remarks

## See also