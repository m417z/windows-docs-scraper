typedef struct _DDFLIPVIDEOPORT {
  HANDLE hDirectDraw;
  HANDLE hVideoPort;
  HANDLE hCurrentSurface;
  HANDLE hTargetSurface;
  DWORD  dwFlags;
} DDFLIPVIDEOPORT, *LPDDFLIPVIDEOPORT;