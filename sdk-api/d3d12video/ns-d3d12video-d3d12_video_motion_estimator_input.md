## Description

Specifies the input parameters for calls to [ID3D12VideoEncodeCommandList::EstimateMotion](https://learn.microsoft.com/windows/win32/api/d3d12video/nf-d3d12video-id3d12videoencodecommandlist-estimatemotion).

## Members

### `pInputTexture2D`

An [ID3D12Resource](https://learn.microsoft.com/windows/win32/api/d3d12/nn-d3d12-id3d12resource) representing the current frame. The motion estimation operation applies to the entire frame.

### `InputSubresourceIndex`

The base plane of the MIP and array slice to use for the input.

### `pReferenceTexture2D`

An [ID3D12Resource](https://learn.microsoft.com/windows/win32/api/d3d12/nn-d3d12-id3d12resource) representing the reference frame, or past frame, used for motion estimation.

### `ReferenceSubresourceIndex`

The base plane of the MIP and array slice to use for the reference.

### `pHintMotionVectorHeap`

An [ID3D12VideoMotionVectorHeap](https://learn.microsoft.com/windows/win32/api/d3d12video/nn-d3d12video-id3d12videomotionvectorheap) representing the buffer containing the hardware-dependent output of the previous motion estimator operation which may be used for hinting the current operation. This parameter may be NULL, indicating that previous motion estimator output should not be considered for the current operation.

## Remarks

## See also