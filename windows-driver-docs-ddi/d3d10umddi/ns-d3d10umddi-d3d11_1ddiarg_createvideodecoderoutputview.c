typedef struct D3D11_1DDIARG_CREATEVIDEODECODEROUTPUTVIEW {
  D3D10DDI_HRESOURCE hDrvResource;
  GUID               DecodeProfile;
  UINT               MipSlice;
  UINT               FirstArraySlice;
  UINT               ArraySize;
} D3D11_1DDIARG_CREATEVIDEODECODEROUTPUTVIEW;