typedef struct D3D12DDI_VIDEO_DECODER_HEAP_SIZE_DATA_0072 {
  UINT                                     NodeMask;
  D3D12DDI_VIDEO_DECODE_CONFIGURATION_0020 Configuration;
  UINT                                     DecodeWidth;
  UINT                                     DecodeHeight;
  DXGI_FORMAT                              Format;
  DXGI_RATIONAL                            FrameRate;
  UINT                                     BitRate;
  UINT                                     MaxDecodePictureBufferCount;
  BOOL                                     Protected;
  UINT64                                   MemoryPoolL0Size;
  UINT64                                   MemoryPoolL1Size;
} D3D12DDI_VIDEO_DECODER_HEAP_SIZE_DATA_0072;