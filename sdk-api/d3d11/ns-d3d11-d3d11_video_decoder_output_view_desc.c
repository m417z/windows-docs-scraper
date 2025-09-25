typedef struct D3D11_VIDEO_DECODER_OUTPUT_VIEW_DESC {
  GUID                 DecodeProfile;
  D3D11_VDOV_DIMENSION ViewDimension;
  union {
    D3D11_TEX2D_VDOV Texture2D;
  };
} D3D11_VIDEO_DECODER_OUTPUT_VIEW_DESC;