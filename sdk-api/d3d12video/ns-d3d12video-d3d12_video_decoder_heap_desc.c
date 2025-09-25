typedef struct D3D12_VIDEO_DECODER_HEAP_DESC {
  UINT                             NodeMask;
  D3D12_VIDEO_DECODE_CONFIGURATION Configuration;
  UINT                             DecodeWidth;
  UINT                             DecodeHeight;
  DXGI_FORMAT                      Format;
  DXGI_RATIONAL                    FrameRate;
  UINT                             BitRate;
  UINT                             MaxDecodePictureBufferCount;
} D3D12_VIDEO_DECODER_HEAP_DESC;