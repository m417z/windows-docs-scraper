typedef struct _UNIFONTOBJ {
  ULONG      ulFontID;
  DWORD      dwFlags;
  IFIMETRICS *pIFIMetrics;
  PFNGETINFO pfnGetInfo;
} UNIFONTOBJ, *PUNIFONTOBJ;