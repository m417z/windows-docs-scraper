typedef struct _VMRALPHABITMAP {
  DWORD                dwFlags;
  HDC                  hdc;
  LPDIRECTDRAWSURFACE7 pDDS;
  RECT                 rSrc;
  NORMALIZEDRECT       rDest;
  FLOAT                fAlpha;
  COLORREF             clrSrcKey;
} VMRALPHABITMAP, *PVMRALPHABITMAP;