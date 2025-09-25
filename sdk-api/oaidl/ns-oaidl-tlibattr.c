typedef struct tagTLIBATTR {
  GUID    guid;
  LCID    lcid;
  SYSKIND syskind;
  WORD    wMajorVerNum;
  WORD    wMinorVerNum;
  WORD    wLibFlags;
} TLIBATTR, *LPTLIBATTR;