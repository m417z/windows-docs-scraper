typedef union _STORAGE_SPEC_VERSION {
  struct {
    union {
      struct {
        UCHAR SubMinor;
        UCHAR Minor;
      } DUMMYSTRUCTNAME;
      USHORT AsUshort;
    } MinorVersion;
    USHORT MajorVersion;
  } DUMMYSTRUCTNAME;
  ULONG  AsUlong;
} STORAGE_SPEC_VERSION, *PSTORAGE_SPEC_VERSION;