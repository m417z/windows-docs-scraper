typedef struct _VIDEOMEMORYINFO {
  FLATPTR       fpPrimary;
  DWORD         dwFlags;
  DWORD         dwDisplayWidth;
  DWORD         dwDisplayHeight;
  LONG          lDisplayPitch;
  DDPIXELFORMAT ddpfDisplay;
  DWORD         dwOffscreenAlign;
  DWORD         dwOverlayAlign;
  DWORD         dwTextureAlign;
  DWORD         dwZBufferAlign;
  DWORD         dwAlphaAlign;
  PVOID         pvPrimary;
} VIDEOMEMORYINFO;