typedef struct D3DWDDM2_0DDI_VIDEO_DECODER_BEGIN_FRAME_CRYPTO_SESSION {
  D3D11_1DDI_HCRYPTOSESSION hCryptoSession;
  void                      *pBlob;
  UINT                      BlobSize;
  GUID                      *pKeyInfoId;
  void                      *pPrivateData;
  UINT                      PrivateDataSize;
} D3DWDDM2_0DDI_VIDEO_DECODER_BEGIN_FRAME_CRYPTO_SESSION;