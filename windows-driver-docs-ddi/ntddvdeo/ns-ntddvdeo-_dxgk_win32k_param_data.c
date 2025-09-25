typedef struct _DXGK_WIN32K_PARAM_DATA {
  PVOID PathsArray;
  PVOID ModesArray;
  ULONG NumPathArrayElements;
  ULONG NumModeArrayElements;
  ULONG SDCFlags;
} DXGK_WIN32K_PARAM_DATA, *PDXGK_WIN32K_PARAM_DATA;