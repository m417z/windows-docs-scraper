# D3D12DDI_VIDEO_DECODE_INPUT_STREAM_ARGUMENTS_0032 structure

## Description

Video decode input stream arguments.

## Members

### `FrameArguments`

The arguments to decode each frame.

### `NumFrameArguments`

The count of frame arguments.

### `ReferenceFrames`

The reference frames needed for decoding this frame. See [D3D12DDI_VIDEO_DECODE_REFERENCE_FRAMES](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_decode_reference_frames_0032).

### `CompressedBitstream`

The compressed bitstream. All source video slices should be placed contiguously (one after another) in this buffer. See [D3D12DDI_VIDEO_COMPRESSED_BITSTREAM](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_decode_compressed_bitstream_0032).

### `DecryptionParameters`

Decryption parameters. When decryption is not used, this structure is zero initialized. See [D3D12DDI_VIDEO_DECODE_DECRYPTION_ARGUMENTS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_decode_decryption_arguments_0030).

### `hDrvVideoDecoderHeap`

Supplies allocations that may contain the state for the current decode operation.