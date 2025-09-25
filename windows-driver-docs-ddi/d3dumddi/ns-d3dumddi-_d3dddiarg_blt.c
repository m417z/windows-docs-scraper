typedef struct _D3DDDIARG_BLT {
  [in] HANDLE          hSrcResource;
  [in] UINT            SrcSubResourceIndex;
  [in] RECT            SrcRect;
  [in] HANDLE          hDstResource;
  [in] UINT            DstSubResourceIndex;
  [in] RECT            DstRect;
  [in] UINT            ColorKey;
  [in] D3DDDI_BLTFLAGS Flags;
} D3DDDIARG_BLT;