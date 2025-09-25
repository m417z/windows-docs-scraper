# D3D12_VIDEO_DECODE_COMPRESSED_BITSTREAM structure

## Description

Represents a compressed bitstream from which video is decoded.

## Members

### `pBuffer`

A pointer to an [ID3D12Resource](https://learn.microsoft.com/windows/desktop/api/d3d12/nn-d3d12-id3d12resource) representing the source buffer containing the compressed bitstream to decode.

### `Offset`

The offset to the beginning of the first slice. This offset has alignment requirements based on the tier value of the video decoder. For more information on decoding tiers, see [D3D12_VIDEO_DECODE_TIER](https://learn.microsoft.com/windows/win32/api/d3d12video/ne-d3d12video-d3d12_video_decode_tier).

### `Size`

The size of the subregion of *pBuffer* that contains the bitstream.

## Remarks

## See also