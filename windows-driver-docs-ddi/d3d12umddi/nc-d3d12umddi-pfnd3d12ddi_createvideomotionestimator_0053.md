# PFND3D12DDI_CREATEVIDEOMOTIONESTIMATOR_0053 callback function

## Description

Creates the video motion estimator.

## Parameters

### `hDrvDevice`

A handle to the display device (graphics context) that the Direct3D runtime uses.

### `pArgs`

Pointer to a [D3D12DDIARG_CREATE_VIDEO_MOTION_ESTIMATOR_0053](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddiarg_create_video_motion_estimator_0053) structure.

### `hDrvMotionEstimator`

A handle to the user mode driver motion estimator type.

## Return value

Returns HRESULT.

## Prototype

```cpp
//Declaration

PFND3D12DDI_CREATEVIDEOMOTIONESTIMATOR_0053 Pfnd3d12ddiCreatevideomotionestimator0053;

// Definition

HRESULT Pfnd3d12ddiCreatevideomotionestimator0053
(
	D3D12DDI_HDEVICE hDrvDevice
	CONST D3D12DDIARG_CREATE_VIDEO_MOTION_ESTIMATOR_0053 *pArgs
	D3D12DDI_HVIDEOMOTIONESTIMATOR_0053 hDrvMotionEstimator
)
{...}

```

## Remarks

The motion estimation operation must support reading from and writing to hardware DRM protected resources when the driver supports Direct3D protected resource support. If the inputs are hardware DRM protected, the runtime will require that the output is a hardware DRM protected resource.

The motion estimation operation is assumed to write to both the D3D12DDI_HVIDEOMOTIONESTIMATOR_0053 context object and to the D3D12DDI_HVIDEOMOTIONVECTORHEAP_0053, so these must be created with a protected resource session when the input textures are protected.

## See also