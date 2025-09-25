typedef struct _DDVIDEOPORTDESC {
  DWORD              dwSize;
  DWORD              dwFieldWidth;
  DWORD              dwVBIWidth;
  DWORD              dwFieldHeight;
  DWORD              dwMicrosecondsPerField;
  DWORD              dwMaxPixelsPerSecond;
  DWORD              dwVideoPortID;
  DWORD              dwReserved1;
  DDVIDEOPORTCONNECT VideoPortType;
  ULONG_PTR          dwReserved2;
  ULONG_PTR          dwReserved3;
} *LPDDVIDEOPORTDESC, DDVIDEOPORTDESC;