# PFND3D12DDI_CALCPRIVATEVIDEOMOTIONESTIMATORSIZE_0053 callback function

## Description

Calculates the driver object size. The Direct3D runtime allocates memory for storing the drivers CPU object representing the motion estimator.

## Parameters

### `hDrvDevice`

A handle to the display device (graphics context) that the Direct3D runtime uses.

### `pArgs`

Pointer to a [D3D12DDIARG_CREATE_VIDEO_MOTION_ESTIMATOR_0053](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddiarg_create_video_motion_estimator_0053) structure.

## Return value

Returns SIZE_T.

## Prototype

```cpp
//Declaration

PFND3D12DDI_CALCPRIVATEVIDEOMOTIONESTIMATORSIZE_0053 Pfnd3d12ddiCalcprivatevideomotionestimatorsize0053;

// Definition

SIZE_T Pfnd3d12ddiCalcprivatevideomotionestimatorsize0053
(
	D3D12DDI_HDEVICE hDrvDevice
	CONST D3D12DDIARG_CREATE_VIDEO_MOTION_ESTIMATOR_0053 *pArgs
)
{...}

```

## Remarks

## See also