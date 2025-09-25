typedef struct tagQUERYCONTEXT {
  DWORD      dwContext;
  CSPLATFORM Platform;
  LCID       Locale;
  DWORD      dwVersionHi;
  DWORD      dwVersionLo;
} QUERYCONTEXT;