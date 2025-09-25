# D3D12DDI_VIDEO_DECODE_CONFIGURATION_0020 structure

## Description

Includes information about the video decode configuration. Contains common parameters for checking capabilities and creating the decoder, decode stream, and the crypto session objects.

## Members

### `DecodeProfile`

The profile for the decoder we want, e.g., HEVC_10BIT, HEVC_8BIT, H264_MAIN.

### `BitstreamEncryption`

The GUID identifying the encryption, e.g., D3D12DDI_DECODER_ENCRYPTION_HW_CENC.

### `InterlaceType`

The interlace type used by the coded frames. See [D3D12DDI_VIDEO_CODED_INTERLACE_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_video_coded_interlace_type_0020).

## Remarks

The decoder object represents a decode session and may contain tracking structures for the overall stream decode. Any significant allocations are expected to live within the decoder heap object.