typedef struct _SURFOBJ {
  DHSURF dhsurf;
  HSURF  hsurf;
  DHPDEV private_dhpdev;
  HDEV   private_hdev;
  DHPDEV dhpdev;
  HDEV   hdev;
  SIZEL  sizlBitmap;
  ULONG  cjBits;
  PVOID  pvBits;
  PVOID  pvScan0;
  LONG   lDelta;
  ULONG  iUniq;
  ULONG  iBitmapFormat;
  USHORT iType;
  USHORT fjBitmap;
} SURFOBJ;