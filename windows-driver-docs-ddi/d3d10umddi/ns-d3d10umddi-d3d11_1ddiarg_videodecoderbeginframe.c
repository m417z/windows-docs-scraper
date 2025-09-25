typedef struct D3D11_1DDIARG_VIDEODECODERBEGINFRAME {
  D3D11_1DDI_HVIDEODECODEROUTPUTVIEW hOutputView;
  const void                         *pContentKey;
  UINT                               ContentKeySize;
} D3D11_1DDIARG_VIDEODECODERBEGINFRAME;