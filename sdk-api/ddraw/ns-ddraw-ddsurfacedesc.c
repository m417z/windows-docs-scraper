typedef struct _DDSURFACEDESC {
  DWORD         dwSize;
  DWORD         dwFlags;
  DWORD         dwHeight;
  DWORD         dwWidth;
#if ...
  union {
    LONG  lPitch;
    DWORD dwLinearSize;
  } DUMMYUNIONNAMEN;
  DWORD         dwBackBufferCount;
#else
  union {
    DWORD dwMipMapCount;
    DWORD dwZBufferBitDepth;
    DWORD dwRefreshRate;
  } DUMMYUNIONNAMEN;
#endif
  DWORD         dwAlphaBitDepth;
  DWORD         dwReserved;
  LPVOID        lpSurface;
  DDCOLORKEY    ddckCKDestOverlay;
  DDCOLORKEY    ddckCKDestBlt;
  DDCOLORKEY    ddckCKSrcOverlay;
  DDCOLORKEY    ddckCKSrcBlt;
  DDPIXELFORMAT ddpfPixelFormat;
  DDSCAPS       ddsCaps;
} *LPDDSURFACEDESC, DDSURFACEDESC;