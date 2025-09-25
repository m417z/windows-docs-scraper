typedef struct _DXVA_PicResample {
  WORD  wPicResampleSourcePicIndex;
  WORD  wPicResampleDestPicIndex;
  WORD  wPicResampleRcontrol;
  BYTE  bPicResampleExtrapWidth;
  BYTE  bPicResampleExtrapHeight;
  DWORD dwPicResampleSourceWidth;
  DWORD dwPicResampleSourceHeight;
  DWORD dwPicResampleDestWidth;
  DWORD dwPicResampleDestHeight;
  DWORD dwPicResampleFullDestWidth;
  DWORD dwPicResampleFullDestHeight;
} DXVA_PicResample, *LPDXVA_PicResample;