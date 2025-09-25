typedef struct D3D11_VIDEO_DECODER_BEGIN_FRAME_CRYPTO_SESSION {
  ID3D11CryptoSession *pCryptoSession;
  UINT                BlobSize;
  void                *pBlob;
  GUID                *pKeyInfoId;
  UINT                PrivateDataSize;
  void                *pPrivateData;
} D3D11_VIDEO_DECODER_BEGIN_FRAME_CRYPTO_SESSION;