typedef struct PACKAGE_VERSION {
  union {
    UINT64 Version;
    struct {
      USHORT Revision;
      USHORT Build;
      USHORT Minor;
      USHORT Major;
    } DUMMYSTRUCTNAME;
  } DUMMYUNIONNAME;
} PACKAGE_VERSION;