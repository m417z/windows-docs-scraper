typedef struct _DD_SETENTRIESDATA {
  PDD_DIRECTDRAW_GLOBAL lpDD;
  PDD_PALETTE_GLOBAL    lpDDPalette;
  DWORD                 dwBase;
  DWORD                 dwNumEntries;
  LPPALETTEENTRY        lpEntries;
  HRESULT               ddRVal;
  VOID                  *SetEntries;
} *PDD_SETENTRIESDATA, DD_SETENTRIESDATA;