typedef struct _D3DDDIARG_VOLUMEBLT1 {
  [in] HANDLE    hDstResource;
  [in] HANDLE    hSrcResource;
  [in] UINT      DstX;
  [in] UINT      DstY;
  [in] UINT      DstZ;
  [in] D3DDDIBOX SrcBox;
       UINT      CopyFlags;
} D3DDDIARG_VOLUMEBLT1;