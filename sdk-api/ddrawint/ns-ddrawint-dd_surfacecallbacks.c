typedef struct DD_SURFACECALLBACKS {
  DWORD                         dwSize;
  DWORD                         dwFlags;
  PDD_SURFCB_DESTROYSURFACE     DestroySurface;
  PDD_SURFCB_FLIP               Flip;
  PDD_SURFCB_SETCLIPLIST        SetClipList;
  PDD_SURFCB_LOCK               Lock;
  PDD_SURFCB_UNLOCK             Unlock;
  PDD_SURFCB_BLT                Blt;
  PDD_SURFCB_SETCOLORKEY        SetColorKey;
  PDD_SURFCB_ADDATTACHEDSURFACE AddAttachedSurface;
  PDD_SURFCB_GETBLTSTATUS       GetBltStatus;
  PDD_SURFCB_GETFLIPSTATUS      GetFlipStatus;
  PDD_SURFCB_UPDATEOVERLAY      UpdateOverlay;
  PDD_SURFCB_SETOVERLAYPOSITION SetOverlayPosition;
  LPVOID                        reserved4;
  PDD_SURFCB_SETPALETTE         SetPalette;
} DD_SURFACECALLBACKS;