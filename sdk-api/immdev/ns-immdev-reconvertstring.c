typedef struct tagRECONVERTSTRING {
  DWORD dwSize;
  DWORD dwVersion;
  DWORD dwStrLen;
  DWORD dwStrOffset;
  DWORD dwCompStrLen;
  DWORD dwCompStrOffset;
  DWORD dwTargetStrLen;
  DWORD dwTargetStrOffset;
} RECONVERTSTRING, *PRECONVERTSTRING, *NPRECONVERTSTRING, *LPRECONVERTSTRING;