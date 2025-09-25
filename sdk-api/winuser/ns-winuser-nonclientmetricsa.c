typedef struct tagNONCLIENTMETRICSA {
  UINT     cbSize;
  int      iBorderWidth;
  int      iScrollWidth;
  int      iScrollHeight;
  int      iCaptionWidth;
  int      iCaptionHeight;
  LOGFONTA lfCaptionFont;
  int      iSmCaptionWidth;
  int      iSmCaptionHeight;
  LOGFONTA lfSmCaptionFont;
  int      iMenuWidth;
  int      iMenuHeight;
  LOGFONTA lfMenuFont;
  LOGFONTA lfStatusFont;
  LOGFONTA lfMessageFont;
  int      iPaddedBorderWidth;
} NONCLIENTMETRICSA, *PNONCLIENTMETRICSA, *LPNONCLIENTMETRICSA;