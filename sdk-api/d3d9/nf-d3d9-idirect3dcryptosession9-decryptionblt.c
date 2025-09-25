HRESULT DecryptionBlt(
  IDirect3DSurface9       *pSrcSurface,
  IDirect3DSurface9       *pDstSurface,
  UINT                    SrcSurfaceSize,
  D3DENCRYPTED_BLOCK_INFO *pEncryptedBlockInfo,
  VOID                    *pContentKey,
  VOID                    *pIV
);