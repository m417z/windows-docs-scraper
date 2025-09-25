struct CHARFORMAT2W : _charformatw {
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