typedef struct D3D12_VIDEO_DECODE_INPUT_STREAM_ARGUMENTS {
  UINT                                    NumFrameArguments;
  D3D12_VIDEO_DECODE_FRAME_ARGUMENT       FrameArguments[10];
  D3D12_VIDEO_DECODE_REFERENCE_FRAMES     ReferenceFrames;
  D3D12_VIDEO_DECODE_COMPRESSED_BITSTREAM CompressedBitstream;
  ID3D12VideoDecoderHeap                  *pHeap;
} D3D12_VIDEO_DECODE_INPUT_STREAM_ARGUMENTS;