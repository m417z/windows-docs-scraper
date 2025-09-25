typedef struct {
  ULONG Size;
  ULONG Version;
  ULONG TestType;
  BYTE  Unused[512];
  ULONG InBufLen;
  BYTE  InBuffer[ANYSIZE_ARRAY];
} GNSS_SELFTESTCONFIG, *PGNSS_SELFTESTCONFIG;