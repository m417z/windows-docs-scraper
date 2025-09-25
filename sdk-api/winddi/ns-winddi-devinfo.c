typedef struct tagDEVINFO {
  FLONG    flGraphicsCaps;
  LOGFONTW lfDefaultFont;
  LOGFONTW lfAnsiVarFont;
  LOGFONTW lfAnsiFixFont;
  ULONG    cFonts;
  ULONG    iDitherFormat;
  USHORT   cxDither;
  USHORT   cyDither;
  HPALETTE hpalDefault;
  FLONG    flGraphicsCaps2;
} DEVINFO, *PDEVINFO;