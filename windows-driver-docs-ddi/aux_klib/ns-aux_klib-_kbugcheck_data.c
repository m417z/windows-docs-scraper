typedef struct _KBUGCHECK_DATA {
  ULONG     BugCheckDataSize;
  ULONG     BugCheckCode;
  ULONG_PTR Parameter1;
  ULONG_PTR Parameter2;
  ULONG_PTR Parameter3;
  ULONG_PTR Parameter4;
} KBUGCHECK_DATA, *PKBUGCHECK_DATA;