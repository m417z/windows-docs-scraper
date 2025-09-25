typedef struct _VMRVIDEOSTREAMINFO {
  LPDIRECTDRAWSURFACE7 pddsVideoSurface;
  DWORD                dwWidth;
  DWORD                dwHeight;
  DWORD                dwStrmID;
  FLOAT                fAlpha;
  DDCOLORKEY           ddClrKey;
  NORMALIZEDRECT       rNormal;
} VMRVIDEOSTREAMINFO;