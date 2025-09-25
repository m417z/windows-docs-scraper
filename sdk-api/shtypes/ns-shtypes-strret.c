typedef struct _STRRET {
  UINT  uType;
  union {
    LPWSTR pOleStr;
    UINT   uOffset;
    char   cStr[260];
  } DUMMYUNIONNAME;
} STRRET;