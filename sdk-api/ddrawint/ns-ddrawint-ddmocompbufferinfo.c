typedef struct _DDMOCOMPBUFFERINFO {
  DWORD             dwSize;
  PDD_SURFACE_LOCAL lpCompSurface;
  DWORD             dwDataOffset;
  DWORD             dwDataSize;
  LPVOID            lpPrivate;
} DDMOCOMPBUFFERINFO, *LPDDMOCOMPBUFFERINFO;