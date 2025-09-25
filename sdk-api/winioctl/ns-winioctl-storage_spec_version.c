typedef union _STORAGE_SPEC_VERSION {
  struct {
    union {
      struct {
        BYTE SubMinor;
        BYTE Minor;
      } DUMMYSTRUCTNAME;
      WORD   AsUshort;
    } MinorVersion;
    WORD MajorVersion;
  } DUMMYSTRUCTNAME;
  DWORD  AsUlong;
} STORAGE_SPEC_VERSION, *PSTORAGE_SPEC_VERSION;