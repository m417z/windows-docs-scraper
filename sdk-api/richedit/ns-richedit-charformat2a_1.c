typedef struct _charformat2a {
  UINT     cbSize;
  DWORD    dwMask;
  DWORD    dwEffects;
  LONG     yHeight;
  LONG     yOffset;
  COLORREF crTextColor;
  BYTE     bCharSet;
  BYTE     bPitchAndFamily;
  char     szFaceName[LF_FACESIZE];
  WORD     wWeight;
  SHORT    sSpacing;
  COLORREF crBackColor;
  LCID     lcid;
  union {
    DWORD dwReserved;
    DWORD dwCookie;
  };
  DWORD    dwReserved;
  SHORT    sStyle;
  WORD     wKerning;
  BYTE     bUnderlineType;
  BYTE     bAnimation;
  BYTE     bRevAuthor;
  BYTE     bUnderlineColor;
} CHARFORMAT2A;