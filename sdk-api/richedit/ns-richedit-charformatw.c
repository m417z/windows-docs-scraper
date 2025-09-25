typedef struct _charformatw {
  UINT     cbSize;
  DWORD    dwMask;
  DWORD    dwEffects;
  LONG     yHeight;
  LONG     yOffset;
  COLORREF crTextColor;
  BYTE     bCharSet;
  BYTE     bPitchAndFamily;
  WCHAR    szFaceName[LF_FACESIZE];
} CHARFORMATW;