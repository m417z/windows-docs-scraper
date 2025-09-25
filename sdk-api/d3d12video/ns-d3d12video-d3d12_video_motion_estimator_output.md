## Description

Specifies the output parameters for calls to [ID3D12VideoEncodeCommandList::EstimateMotion](https://learn.microsoft.com/windows/win32/api/d3d12video/nf-d3d12video-id3d12videoencodecommandlist-estimatemotion).

## Members

### `pMotionVectorHeap`

An [ID3D12VideoMotionVectorHeap](https://learn.microsoft.com/windows/win32/api/d3d12video/nn-d3d12video-id3d12videomotionvectorheap) containing the resolved motion estimation vectors. Motion vectors are resolved to a [DXGI_FORMAT_R16G16_SINT](https://learn.microsoft.com/windows/win32/api/dxgiformat/ne-dxgiformat-dxgi_format) 2D texture. The resolved data is a signed 16-byte integer with quarter PEL units with the X vector component stored in the R component and the Y vector component stored in the G component. Motion vectors are stored in a 2D layout that corresponds to the pixel layout of the original input textures.

## Remarks

Call [ID3D12VideoEncodeCommandList::ResolveMotionVectorHeap](https://learn.microsoft.com/windows/win32/api/d3d12video/nf-d3d12video-id3d12videoencodecommandlist-resolvemotionvectorheap) to translate the motion vector output of the [EstimateMotion](https://learn.microsoft.com/windows/win32/api/d3d12video/nf-d3d12video-id3d12videoencodecommandlist-estimatemotion) method from hardware-dependent formats into a consistent format defined by the video motion estimation APIs.

## See also

[ID3D12VideoEncodeCommandList::EstimateMotion](https://learn.microsoft.com/windows/win32/api/d3d12video/nf-d3d12video-id3d12videoencodecommandlist-estimatemotion)
[ID3D12VideoEncodeCommandList::ResolveMotionVectorHeap](https://learn.microsoft.com/windows/win32/api/d3d12video/nf-d3d12video-id3d12videoencodecommandlist-resolvemotionvectorheap)