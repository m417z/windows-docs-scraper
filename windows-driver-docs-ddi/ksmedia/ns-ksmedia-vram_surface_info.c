typedef struct {
  UINT_PTR  hSurface;
  LONGLONG  VramPhysicalAddress;
  DWORD     cbCaptured;
  DWORD     dwWidth;
  DWORD     dwHeight;
  DWORD     dwLinearSize;
  LONG      lPitch;
  ULONGLONG ullReserved[16];
} VRAM_SURFACE_INFO, *PVRAM_SURFACE_INFO;