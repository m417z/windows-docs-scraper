## Description

Allocates heap that contains motion vectors for video motion estimation.

## Parameters

### `pDesc`

A pointer to a [D3D12_VIDEO_MOTION_VECTOR_HEAP_DESC](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_video_motion_vector_heap_desc) describing the format of the heap. This structure contains both input and output fields.

### `pProtectedResourceSession`

A [ID3D12ProtectedResourceSession](https://learn.microsoft.com/windows/win32/api/d3d12/nn-d3d12-id3d12protectedresourcesession) for managing access to protected resources.

### `riid`

The globally unique identifier (GUID) for the **ID3D12VideoMotionVectorHeap** interface.

### `ppVideoMotionVectorHeap`

A pointer to a memory block that receives a pointer to the **ID3D12VideoMotionVectorHeap** interface.

## Return value

This method returns HRESULT.

## Remarks

## See also