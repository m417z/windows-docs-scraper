# D3D12_VIDEO_DECODER_DESC structure

## Description

Describes a [ID3D12VideoDecoder](https://learn.microsoft.com/windows/win32/api/d3d12video/nn-d3d12video-id3d12videodecoder). Pass this structure into [ID3D12VideoDevice::CreateVideoDecoder](https://learn.microsoft.com/windows/win32/api/d3d12video/nf-d3d12video-id3d12videodevice-createvideodecoder) to create an instance of **ID3D12VideoDecoder**.

## Members

### `NodeMask`

The node mask specifying the physical adapter on which the video processor will be used. For single GPU operation, set this to zero. If there are multiple GPU nodes, set a bit to identify the node, i.e. the device's physical adapter, to which the command queue applies. Each bit in the mask corresponds to a single node. Only 1 bit may be set.

### `Configuration`

A [D3D12_VIDEO_DECODE_CONFIGURATION](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_video_decode_configuration) structure specifying the configuration of the video decoder.

## Remarks

## See also