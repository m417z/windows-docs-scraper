typedef struct DESKBANDINFO {
  DWORD    dwMask;
  POINTL   ptMinSize;
  POINTL   ptMaxSize;
  POINTL   ptIntegral;
  POINTL   ptActual;
  WCHAR    wszTitle[256];
  DWORD    dwModeFlags;
  COLORREF crBkgnd;
} DESKBANDINFO;