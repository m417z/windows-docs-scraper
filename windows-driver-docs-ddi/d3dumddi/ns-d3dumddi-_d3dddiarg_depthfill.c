typedef struct _D3DDDIARG_DEPTHFILL {
  [in] HANDLE hResource;
  [in] UINT   SubResourceIndex;
  [in] RECT   DstRect;
       UINT   Depth;
} D3DDDIARG_DEPTHFILL;