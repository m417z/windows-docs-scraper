typedef struct _NS_HELPER_ATTRIBUTES {
  union {
    struct {
      DWORD dwVersion;
      DWORD dwReserved;
    };
    ULONGLONG _ullAlign;
  };
  GUID                guidHelper;
  PNS_HELPER_START_FN pfnStart;
  PNS_HELPER_STOP_FN  pfnStop;
} NS_HELPER_ATTRIBUTES, *PNS_HELPER_ATTRIBUTES;