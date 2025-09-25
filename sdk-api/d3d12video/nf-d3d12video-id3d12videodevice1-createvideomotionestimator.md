## Description

Creates an [ID3D12VideoMotionEstimator](https://learn.microsoft.com/windows/win32/api/d3d12video/nn-d3d12video-id3d12videomotionestimator), which maintains context for video motion estimation operations.

## Parameters

### `pDesc`

A [D3D12_VIDEO_MOTION_ESTIMATOR_DESC](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_video_motion_estimator_desc) describing the parameters used for motion estimation. This structure contains both input and output fields.

### `pProtectedResourceSession`

A [ID3D12ProtectedResourceSession](https://learn.microsoft.com/windows/win32/api/d3d12/nn-d3d12-id3d12protectedresourcesession) for managing access to protected resources.

### `riid`

The globally unique identifier (GUID) for the **ID3D12VideoMotionEstimator** interface.

### `ppVideoMotionEstimator`

A pointer to a memory block that receives a pointer to the **ID3D12VideoMotionEstimator** interface.

## Return value

This method returns HRESULT.

## Remarks

## See also