typedef struct DD_CALLBACKS {
  DWORD                    dwSize;
  DWORD                    dwFlags;
  PDD_DESTROYDRIVER        DestroyDriver;
  PDD_CREATESURFACE        CreateSurface;
  PDD_SETCOLORKEY          SetColorKey;
  PDD_SETMODE              SetMode;
  PDD_WAITFORVERTICALBLANK WaitForVerticalBlank;
  PDD_CANCREATESURFACE     CanCreateSurface;
  PDD_CREATEPALETTE        CreatePalette;
  PDD_GETSCANLINE          GetScanLine;
  PDD_MAPMEMORY            MapMemory;
} DD_CALLBACKS;