typedef struct _DDCOMPBUFFERINFO {
  DWORD         dwSize;
  DWORD         dwNumCompBuffers;
  DWORD         dwWidthToCreate;
  DWORD         dwHeightToCreate;
  DWORD         dwBytesToAllocate;
  DDSCAPS2      ddCompCaps;
  DDPIXELFORMAT ddPixelFormat;
} DDCOMPBUFFERINFO, *LPDDCOMPBUFFERINFO;