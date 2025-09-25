## Description

Retrieves the memory allocation size of a video decoder heap created with the given properties.

## Members

### `NodeMask`

For a single GPU operation, set this to zero. If there are multiple GPU nodes, set a bit to identify the node (the device's physical adapter) to which the command queue applies. Each bit in the mask corresponds to a single node. Only 1 bit may be set.

### `Configuration`

A [**D3D12DDI_VIDEO_DECODE_CONFIGURATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_decode_configuration_0020) structure with the decode profile and bitstream encryption.

### `DecodeWidth`

The decode width of the bitstream to be decoded.

### `DecodeHeight`

The decode height of the bitstream to be decoded.

### `Format`

The resource data format.

### `FrameRate`

The frame rate of the input video stream.

### `BitRate`

The bits per second data compression rate for the compressed video stream.

### `MaxDecodePictureBufferCount`

The maximum number of decode picture buffers that this stream can have.

### `Protected`

If TRUE, the decoder is created with a protected resource session and used with protected resources.

### `MemoryPoolL0Size`

The L0 size of the heap object. Memory Pool L0 is the memory pool “closest” to the GPU. In the case of UMA adapters, this is the amount of system memory used. For discrete adapters, this is the amount of discrete memory used.

### `MemoryPoolL1Size`

The L1 size of the heap object. Memory Pool L1 is the memory pool “second closest” to the GPU. In the case of UMA adapters, this value is zero. In the case of discrete adapters, this is the amount of system memory used.

## Remarks

This structure is for the D3D12DDICAPS_TYPE_VIDEO_0032_DECODER_HEAP_SIZE capability check in [D3D12DDICAPS_TYPE_VIDEO_0020](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddicaps_type_video_0020).

See the [D3D Video Protected Resource Support Specification](https://microsoft.github.io/DirectX-Specs/d3d/D3D12_Video_ProtectedResourceSupport.html) for more information.

## See also

[**D3D12DDI_VIDEO_DECODE_CONFIGURATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_decode_configuration_0020)

[D3D12DDICAPS_TYPE_VIDEO_0020](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddicaps_type_video_0020)