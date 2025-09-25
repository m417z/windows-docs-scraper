typedef struct _D3DDDIARG_DECRYPTIONBLT {
  [in] HANDLE                     hCryptoSession;
  [in] HANDLE                     hSrcResource;
  [in] UINT                       SrcSubResourceIndex;
  [in] HANDLE                     hDstResource;
  [in] UINT                       DstSubResourceIndex;
  [in] UINT                       SrcResourceSize;
  [in] D3DDDIENCRYPTED_BLOCK_INFO *pEncryptedBlockInfo;
  [in] VOID                       *pContentKey;
  [in] VOID                       *pIV;
} D3DDDIARG_DECRYPTIONBLT;