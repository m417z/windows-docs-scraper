typedef struct _D3DDDIARG_BUFFERBLT1 {
  HANDLE      hDstResource;
  HANDLE      hSrcResource;
  UINT        Offset;
  D3DDDIRANGE SrcRange;
  UINT        CopyFlags;
} D3DDDIARG_BUFFERBLT1;