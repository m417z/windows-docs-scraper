typedef struct _WSAMSG {
  LPSOCKADDR name;
  INT        namelen;
  LPWSABUF   lpBuffers;
#if ...
  ULONG      dwBufferCount;
#else
  DWORD      dwBufferCount;
#endif
  WSABUF     Control;
#if ...
  ULONG      dwFlags;
#else
  DWORD      dwFlags;
#endif
} WSAMSG, *PWSAMSG, *LPWSAMSG;