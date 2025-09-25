typedef struct _D3DDDIARG_COLORFILL {
  [in] HANDLE                hResource;
  [in] UINT                  SubResourceIndex;
  [in] RECT                  DstRect;
       D3DCOLOR              Color;
  [in] D3DDDI_COLORFILLFLAGS Flags;
} D3DDDIARG_COLORFILL;