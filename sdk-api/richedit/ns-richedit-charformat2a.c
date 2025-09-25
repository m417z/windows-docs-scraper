struct CHARFORMAT2A : _charformat {
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
};