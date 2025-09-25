typedef struct _MODLOAD_DATA {
  DWORD ssize;
  DWORD ssig;
  PVOID data;
  DWORD size;
  DWORD flags;
} MODLOAD_DATA, *PMODLOAD_DATA;