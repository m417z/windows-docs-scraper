typedef struct D3D11DDIARG_CREATERESOURCE {
  [in]      const D3D10DDI_MIPINFO               *pMipInfoList;
  [in]      const D3D10_DDIARG_SUBRESOURCE_UP    *pInitialDataUP;
  [in]      D3D10DDIRESOURCE_TYPE                ResourceDimension;
  [in]      UINT                                 Usage;
  [in]      UINT                                 BindFlags;
  [in]      UINT                                 MapFlags;
  [in]      UINT                                 MiscFlags;
  [in]      DXGI_FORMAT                          Format;
  [in]      DXGI_SAMPLE_DESC                     SampleDesc;
  [in]      UINT                                 MipLevels;
  [in]      UINT                                 ArraySize;
  [in, out] DXGI_DDI_PRIMARY_DESC                *pPrimaryDesc;
  [in]      UINT                                 ByteStride;
  [in]      D3D11_1DDI_VIDEO_DECODER_BUFFER_TYPE DecoderBufferType;
            D3DWDDM2_0DDI_TEXTURE_LAYOUT         TextureLayout;
} D3D11DDIARG_CREATERESOURCE;