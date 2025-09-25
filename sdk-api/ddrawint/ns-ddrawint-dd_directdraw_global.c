typedef struct _DD_DIRECTDRAW_GLOBAL {
  VOID              *dhpdev;
  ULONG_PTR         dwReserved1;
  ULONG_PTR         dwReserved2;
  LPDDVIDEOPORTCAPS lpDDVideoPortCaps;
} *PDD_DIRECTDRAW_GLOBAL, DD_DIRECTDRAW_GLOBAL;