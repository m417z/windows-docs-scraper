typedef struct _PROPSHEETHEADERW_V2 {
  union {
    HBITMAP hbmWatermark;
    LPCWSTR pszbmWatermark;
  } DUMMYUNIONNAME4;
  HPALETTE hplWatermark;
  union {
    HBITMAP hbmHeader;
    LPCWSTR pszbmHeader;
  } DUMMYUNIONNAME5;
} PROPSHEETHEADERW_V2, *LPPROPSHEETHEADERW_V2;