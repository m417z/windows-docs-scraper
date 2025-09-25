# D3D12_VIDEO_DECODER_HEAP_DESC structure

## Description

Describes a [ID3D12VideoDecoderHeap](https://learn.microsoft.com/windows/win32/api/d3d12video/nn-d3d12video-id3d12videodecoderheap). Pass this structure into [ID3D12VideoDevice::CreateVideoDecoderHeap](https://learn.microsoft.com/windows/win32/api/d3d12video/nf-d3d12video-id3d12videodevice-createvideodecoderheap) to create an instance of **ID3D12VideoDecoderHeap**.

## Members

### `NodeMask`

The node mask specifying the physical adapter on which the video processor will be used. For single GPU operation, set this to zero. If there are multiple GPU nodes, set a bit to identify the node, i.e. the device's physical adapter, to which the command queue applies. Each bit in the mask corresponds to a single node. Only 1 bit may be set.

### `Configuration`

A [D3D12_VIDEO_DECODE_CONFIGURATION](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_video_decode_configuration) structure specifying the configuration of the video decoder.

### `DecodeWidth`

The decode width of the bitstream to be decoded.

### `DecodeHeight`

The decode height of the bitstream to be decoded.

### `Format`

A [DXGI_FORMAT](https://learn.microsoft.com/windows/desktop/api/dxgiformat/ne-dxgiformat-dxgi_format) structure specifying the format of the bitstream to be decoded.

### `FrameRate`

The frame rate of the input video stream. For more information, see the Remarks section.

### `BitRate`

The average bits per second data compression rate for the compressed video stream. For more information, see the Remarks section.

### `MaxDecodePictureBufferCount`

The maximum number of decode picture buffers this stream can have.

## Remarks

The *BitRate* and *FrameRate* parameters may be used by drivers to inform heuristics such as intermediate allocation sizes. Decoding a frame may fail if these values are insufficient for the video stream. Use [D3D12_QUERY_DATA_VIDEO_DECODE_STATISTICS](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_query_data_video_decode_statistics) to determine if the video decode succeeded. If decode fails due to insufficient *BitRate* and *FrameRate* parameters, the *Status* field of this query is set to [D3D12_VIDEO_DECODE_STATUS_RATE_EXCEEDED](https://learn.microsoft.com/windows/win32/api/d3d12video/ne-d3d12video-d3d12_video_decode_status). This query also returns new *BitRate* and *FrameRate* values that would succeed.

The *BitRate* and *FrameRate* parameters may also be set to zero. Drivers make worst-case assumptions when these values are used which may result in higher memory consumption with some adapters.

## See also