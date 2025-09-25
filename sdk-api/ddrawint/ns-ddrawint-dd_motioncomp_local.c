typedef struct _DD_MOTIONCOMP_LOCAL {
  PDD_DIRECTDRAW_LOCAL lpDD;
  GUID                 guid;
  DWORD                dwUncompWidth;
  DWORD                dwUncompHeight;
  DDPIXELFORMAT        ddUncompPixelFormat;
  DWORD                dwDriverReserved1;
  DWORD                dwDriverReserved2;
  DWORD                dwDriverReserved3;
  LPVOID               lpDriverReserved1;
  LPVOID               lpDriverReserved2;
  LPVOID               lpDriverReserved3;
} *PDD_MOTIONCOMP_LOCAL, DD_MOTIONCOMP_LOCAL;