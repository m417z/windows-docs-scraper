typedef struct _DDSURFACEDESC2 {
  DWORD      dwSize;
  DWORD      dwFlags;
  DWORD      dwHeight;
  DWORD      dwWidth;
#if ...
  union {
    LONG  lPitch;
    DWORD dwLinearSize;
  } DUMMYUNIONNAMEN;
#elif
  union {
    DWORD dwBackBufferCount;
    DWORD dwDepth;
  } DUMMYUNIONNAMEN;
#elif
  union {
    DWORD dwMipMapCount;
    DWORD dwRefreshRate;
    DWORD dwSrcVBHandle;
  } DUMMYUNIONNAMEN;
  DWORD      dwAlphaBitDepth;
  DWORD      dwReserved;
  LPVOID     lpSurface;
#elif
  union {
    DDCOLORKEY ddckCKDestOverlay;
    DWORD      dwEmptyFaceColor;
  } DUMMYUNIONNAMEN;
  DDCOLORKEY ddckCKDestBlt;
  DDCOLORKEY ddckCKSrcOverlay;
  DDCOLORKEY ddckCKSrcBlt;
#else
  union {
    DDPIXELFORMAT ddpfPixelFormat;
    DWORD         dwFVF;
  } DUMMYUNIONNAMEN;
#endif
  DDSCAPS2   ddsCaps;
  DWORD      dwTextureStage;
} *LPDDSURFACEDESC2, DDSURFACEDESC2;