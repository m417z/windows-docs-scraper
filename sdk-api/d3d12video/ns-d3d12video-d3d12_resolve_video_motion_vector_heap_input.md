## Description

Provides input data for calls to [ID3D12VideoEncodeCommandList::ResolveMotionVectorHeap](https://learn.microsoft.com/windows/win32/api/d3d12video/nf-d3d12video-id3d12videoencodecommandlist-resolvemotionvectorheap).

## Members

### `pMotionVectorHeap`

The [ID3D12VideoMotionVectorHeap](https://learn.microsoft.com/windows/win32/api/d3d12video/nn-d3d12video-id3d12videomotionvectorheap) containing the hardware-dependent data layout of the motion search.

### `PixelWidth`

The pixel width of the texture that the motion estimation operation was performed on. The motion estimator heap may be allocated to support a size range, this parameter informs the size of the last motion estimation operation.

### `PixelHeight`

The pixel height of the texture that the motion estimation operation was performed on. The motion estimator heap may be allocated to support a size range, this parameter informs the size of the last motion estimation operation.

## Remarks

## See also