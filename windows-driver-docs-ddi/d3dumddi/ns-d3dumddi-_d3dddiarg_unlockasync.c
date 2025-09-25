typedef struct _D3DDDIARG_UNLOCKASYNC {
  [in] HANDLE                  hResource;
  [in] UINT                    SubResourceIndex;
  [in] D3DDDI_UNLOCKASYNCFLAGS Flags;
} D3DDDIARG_UNLOCKASYNC;