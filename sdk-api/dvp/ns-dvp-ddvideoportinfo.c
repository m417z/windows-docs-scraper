typedef struct _DDVIDEOPORTINFO {
  DWORD           dwSize;
  DWORD           dwOriginX;
  DWORD           dwOriginY;
  DWORD           dwVPFlags;
  RECT            rCrop;
  DWORD           dwPrescaleWidth;
  DWORD           dwPrescaleHeight;
  LPDDPIXELFORMAT lpddpfInputFormat;
  LPDDPIXELFORMAT lpddpfVBIInputFormat;
  LPDDPIXELFORMAT lpddpfVBIOutputFormat;
  DWORD           dwVBIHeight;
  ULONG_PTR       dwReserved1;
  ULONG_PTR       dwReserved2;
} *LPDDVIDEOPORTINFO, DDVIDEOPORTINFO;