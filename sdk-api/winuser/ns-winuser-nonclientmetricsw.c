typedef struct tagNONCLIENTMETRICSW {
  UINT     cbSize;
  int      iBorderWidth;
  int      iScrollWidth;
  int      iScrollHeight;
  int      iCaptionWidth;
  int      iCaptionHeight;
  LOGFONTW lfCaptionFont;
  int      iSmCaptionWidth;
  int      iSmCaptionHeight;
  LOGFONTW lfSmCaptionFont;
  int      iMenuWidth;
  int      iMenuHeight;
  LOGFONTW lfMenuFont;
  LOGFONTW lfStatusFont;
  LOGFONTW lfMessageFont;
  int      iPaddedBorderWidth;
} NONCLIENTMETRICSW, *PNONCLIENTMETRICSW, *LPNONCLIENTMETRICSW;