typedef struct _D3DDDIARG_VOLUMEBLT {
  [in] HANDLE    hDstResource;
  [in] HANDLE    hSrcResource;
  [in] UINT      DstX;
  [in] UINT      DstY;
  [in] UINT      DstZ;
  [in] D3DDDIBOX SrcBox;
} D3DDDIARG_VOLUMEBLT;