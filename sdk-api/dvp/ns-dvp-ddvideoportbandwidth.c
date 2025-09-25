typedef struct _DDVIDEOPORTBANDWIDTH {
  DWORD     dwSize;
  DWORD     dwCaps;
  DWORD     dwOverlay;
  DWORD     dwColorkey;
  DWORD     dwYInterpolate;
  DWORD     dwYInterpAndColorkey;
  ULONG_PTR dwReserved1;
  ULONG_PTR dwReserved2;
} *LPDDVIDEOPORTBANDWIDTH, DDVIDEOPORTBANDWIDTH;