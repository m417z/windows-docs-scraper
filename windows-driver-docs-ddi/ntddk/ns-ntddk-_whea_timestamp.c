typedef union _WHEA_TIMESTAMP {
  struct {
    ULONGLONG Seconds : 8;
    ULONGLONG Minutes : 8;
    ULONGLONG Hours : 8;
    ULONGLONG Precise : 1;
    ULONGLONG Reserved : 7;
    ULONGLONG Day : 8;
    ULONGLONG Month : 8;
    ULONGLONG Year : 8;
    ULONGLONG Century : 8;
  } DUMMYSTRUCTNAME;
  LARGE_INTEGER AsLARGE_INTEGER;
} WHEA_TIMESTAMP, *PWHEA_TIMESTAMP;