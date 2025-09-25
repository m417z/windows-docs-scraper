typedef struct _charformat {
  UINT     cbSize;
  DWORD    dwMask;
  DWORD    dwEffects;
  LONG     yHeight;
  LONG     yOffset;
  COLORREF crTextColor;
  BYTE     bCharSet;
  BYTE     bPitchAndFamily;
  char     szFaceName[LF_FACESIZE];
} CHARFORMATA;