typedef struct D3D10DDIARG_CREATERESOURCE {
  [in]      const D3D10DDI_MIPINFO            *pMipInfoList;
  [in]      const D3D10_DDIARG_SUBRESOURCE_UP *pInitialDataUP;
  [in]      D3D10DDIRESOURCE_TYPE             ResourceDimension;
  [in]      UINT                              Usage;
  [in]      UINT                              BindFlags;
  [in]      UINT                              MapFlags;
  [in]      UINT                              MiscFlags;
  [in]      DXGI_FORMAT                       Format;
  [in]      DXGI_SAMPLE_DESC                  SampleDesc;
  [in]      UINT                              MipLevels;
  [in]      UINT                              ArraySize;
  [in, out] DXGI_DDI_PRIMARY_DESC             *pPrimaryDesc;
} D3D10DDIARG_CREATERESOURCE;