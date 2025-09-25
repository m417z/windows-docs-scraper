typedef struct _PROPSHEETHEADERA_V2 {
  union {
    HBITMAP hbmWatermark;
    LPCSTR  pszbmWatermark;
  } DUMMYUNIONNAME4;
  HPALETTE hplWatermark;
  union {
    HBITMAP hbmHeader;
    LPCSTR  pszbmHeader;
  } DUMMYUNIONNAME5;
} PROPSHEETHEADERA_V2, *LPPROPSHEETHEADERA_V2;