typedef struct _D3DDDIARG_UNLOCK {
  [in] HANDLE             hResource;
  [in] UINT               SubResourceIndex;
  [in] D3DDDI_UNLOCKFLAGS Flags;
} D3DDDIARG_UNLOCK;