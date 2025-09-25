typedef struct _DDFLIPOVERLAY {
  HANDLE hDirectDraw;
  HANDLE hCurrentSurface;
  HANDLE hTargetSurface;
  DWORD  dwFlags;
} DDFLIPOVERLAY, *LPDDFLIPOVERLAY;