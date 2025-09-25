typedef struct _DD_VIDEOPORT_LOCAL {
  PDD_DIRECTDRAW_LOCAL lpDD;
  DDVIDEOPORTDESC      ddvpDesc;
  DDVIDEOPORTINFO      ddvpInfo;
  PDD_SURFACE_INT      lpSurface;
  PDD_SURFACE_INT      lpVBISurface;
  DWORD                dwNumAutoflip;
  DWORD                dwNumVBIAutoflip;
  ULONG_PTR            dwReserved1;
  ULONG_PTR            dwReserved2;
  ULONG_PTR            dwReserved3;
} *PDD_VIDEOPORT_LOCAL, DD_VIDEOPORT_LOCAL;