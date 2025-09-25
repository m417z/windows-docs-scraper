typedef struct tagFONTDESC {
  UINT     cbSizeofstruct;
  LPOLESTR lpstrName;
  CY       cySize;
  SHORT    sWeight;
  SHORT    sCharset;
  BOOL     fItalic;
  BOOL     fUnderline;
  BOOL     fStrikethrough;
} FONTDESC, *LPFONTDESC;