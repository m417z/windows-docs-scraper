typedef struct D3DDDIARG_UPDATESUBRESOURCEUP {
  HANDLE              hResource;
  UINT                SubResourceIndex;
  D3DDDIBOX           DstBox;
  const VOID          *pSysMemUP;
  UINT                RowPitch;
  UINT                DepthPitch;
  D3DDDIARG_COPYFLAGS Flags;
} D3DDDIARG_UPDATESUBRESOURCEUP;