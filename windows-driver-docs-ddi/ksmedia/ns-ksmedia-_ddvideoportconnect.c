typedef struct _DDVIDEOPORTCONNECT {
  DWORD     dwSize;
  DWORD     dwPortWidth;
  GUID      guidTypeID;
  DWORD     dwFlags;
  ULONG_PTR dwReserved1;
} DDVIDEOPORTCONNECT, *LPDDVIDEOPORTCONNECT;