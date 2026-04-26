## Description

Contains quantization matrix input data for [ID3D12VideoEncodeCommandList4::ResolveInputParamLayout](https://learn.microsoft.com/windows/win32/api/d3d12video/nf-d3d12video-id3d12videoencodecommandlist4-resolveinputparamlayout).

## Members

### `pQuantizationMap`

Pointer to an ID3D12Resource texture with format DXGI_FORMAT_R8_SINT for H264 and HEVC, or DXGI_FORMAT_R16_SINT for AV1. The dimensions must correspond with the driver-supported QP Map region block size and the current frame resolution, where each (x, y) position on this texture corresponds to the QP value used on that block.

## Remarks

QPMap width is calculated as `(align(FrameResolution.Width, BlockSize) / BlockSize)` and height as `(align(FrameResolution.Height, BlockSize) / BlockSize)`.

For codecs and configurations where QP ranges can be negative, the ranges used by pQuantizationMap as an absolute map are kept in the native signed range. For example, for HEVC the range is [0, 51] for 8-bit pixel depth, [-12, 51] for 10-bit, and similar for higher bit depths.

## See also