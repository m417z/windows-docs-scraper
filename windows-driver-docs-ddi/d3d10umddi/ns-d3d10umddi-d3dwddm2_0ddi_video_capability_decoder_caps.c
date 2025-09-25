typedef struct D3DWDDM2_0DDI_VIDEO_CAPABILITY_DECODER_CAPS {
  GUID          DecodeProfile;
  UINT          SampleWidth;
  UINT          SampleHeight;
  DXGI_RATIONAL FrameRate;
  UINT          BitRate;
  const GUID    *pCryptoType;
  UINT          Caps;
} D3DWDDM2_0DDI_VIDEO_CAPABILITY_DECODER_CAPS;