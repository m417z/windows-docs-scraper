typedef struct _DD_CREATEPALETTEDATA {
  PDD_DIRECTDRAW_GLOBAL lpDD;
  PDD_PALETTE_GLOBAL    lpDDPalette;
  LPPALETTEENTRY        lpColorTable;
  HRESULT               ddRVal;
  VOID                  *CreatePalette;
  BOOL                  is_excl;
} *PDD_CREATEPALETTEDATA, DD_CREATEPALETTEDATA;