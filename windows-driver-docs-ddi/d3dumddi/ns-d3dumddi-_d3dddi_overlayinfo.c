typedef struct _D3DDDI_OVERLAYINFO {
  [in] HANDLE                  hResource;
  [in] UINT                    SubResourceIndex;
  [in] RECT                    DstRect;
  [in] RECT                    SrcRect;
  [in] UINT                    DstColorKeyLow;
  [in] UINT                    DstColorKeyHigh;
  [in] UINT                    SrcColorKeyLow;
  [in] UINT                    SrcColorKeyHigh;
  [in] D3DDDI_OVERLAYINFOFLAGS Flags;
} D3DDDI_OVERLAYINFO;