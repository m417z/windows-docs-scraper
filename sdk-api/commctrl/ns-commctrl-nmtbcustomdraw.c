typedef struct _NMTBCUSTOMDRAW {
  NMCUSTOMDRAW nmcd;
  HBRUSH       hbrMonoDither;
  HBRUSH       hbrLines;
  HPEN         hpenLines;
  COLORREF     clrText;
  COLORREF     clrMark;
  COLORREF     clrTextHighlight;
  COLORREF     clrBtnFace;
  COLORREF     clrBtnHighlight;
  COLORREF     clrHighlightHotTrack;
  RECT         rcText;
  int          nStringBkMode;
  int          nHLStringBkMode;
  int          iListGap;
} NMTBCUSTOMDRAW, *LPNMTBCUSTOMDRAW;