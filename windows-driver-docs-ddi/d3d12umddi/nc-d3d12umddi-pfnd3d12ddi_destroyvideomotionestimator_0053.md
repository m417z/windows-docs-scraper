# PFND3D12DDI_DESTROYVIDEOMOTIONESTIMATOR_0053 callback function

## Description

Destroys the video motion estimator.

## Parameters

### `hDrvDevice`

A handle to the display device (graphics context) that the Direct3D runtime uses.

### `hDrvMotionEstimator`

A handle to the user mode driver motion estimator type.

## Prototype

```cpp
//Declaration

PFND3D12DDI_DESTROYVIDEOMOTIONESTIMATOR_0053 Pfnd3d12ddiDestroyvideomotionestimator0053;

// Definition

VOID Pfnd3d12ddiDestroyvideomotionestimator0053
(
	D3D12DDI_HDEVICE hDrvDevice
	D3D12DDI_HVIDEOMOTIONESTIMATOR_0053 hDrvMotionEstimator
)
{...}

```

## Remarks

## See also