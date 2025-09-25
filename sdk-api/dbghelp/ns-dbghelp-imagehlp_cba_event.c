typedef struct _IMAGEHLP_CBA_EVENT {
  DWORD severity;
  DWORD code;
  PCHAR desc;
  PVOID object;
} IMAGEHLP_CBA_EVENT, *PIMAGEHLP_CBA_EVENT;