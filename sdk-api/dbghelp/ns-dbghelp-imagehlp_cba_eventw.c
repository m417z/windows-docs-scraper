typedef struct _IMAGEHLP_CBA_EVENTW {
  DWORD  severity;
  DWORD  code;
  PCWSTR desc;
  PVOID  object;
} IMAGEHLP_CBA_EVENTW, *PIMAGEHLP_CBA_EVENTW;