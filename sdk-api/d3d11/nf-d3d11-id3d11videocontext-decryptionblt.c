void DecryptionBlt(
  [in] ID3D11CryptoSession        *pCryptoSession,
  [in] ID3D11Texture2D            *pSrcSurface,
  [in] ID3D11Texture2D            *pDstSurface,
  [in] D3D11_ENCRYPTED_BLOCK_INFO *pEncryptedBlockInfo,
  [in] UINT                       ContentKeySize,
  [in] const void                 *pContentKey,
  [in] UINT                       IVSize,
  [in] void                       *pIV
);