typedef struct _UMDF_IO_TARGET_OPEN_PARAMS {
  DWORD dwShareMode;
  DWORD dwCreationDisposition;
  DWORD dwFlagsAndAttributes;
} UMDF_IO_TARGET_OPEN_PARAMS, *PUMDF_IO_TARGET_OPEN_PARAMS;