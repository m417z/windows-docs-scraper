typedef struct D3D12DDIARG_CREATE_VIDEO_DECODER_HEAP_0072 {
  UINT                                     NodeMask;
  D3D12DDI_VIDEO_DECODE_CONFIGURATION_0020 Configuration;
  UINT                                     DecodeWidth;
  UINT                                     DecodeHeight;
  DXGI_FORMAT                              Format;
  DXGI_RATIONAL                            FrameRate;
  UINT                                     BitRate;
  UINT                                     MaxDecodePictureBufferCount;
  D3D12DDI_HPROTECTEDRESOURCESESSION_0030  hDrvProtectedResourceSession;
} D3D12DDIARG_CREATE_VIDEO_DECODER_HEAP_0072;