typedef struct _D3DDDIARG_BUFFERBLT {
  [in] HANDLE      hDstResource;
  [in] HANDLE      hSrcResource;
  [in] UINT        Offset;
  [in] D3DDDIRANGE SrcRange;
} D3DDDIARG_BUFFERBLT;