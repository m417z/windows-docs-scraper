typedef enum GdiplusStartupParams {
  GdiplusStartupDefault = 0x00000000,
  GdiplusStartupNoSetRound = 0x00000001,
  GdiplusStartupSetPSValue = 0x00000002,
  GdiplusStartupReserved0 = 0x00000004,
  GdiplusStartupReserved1,
  GdiplusStartupReserved2,
  GdiplusStartupTransparencyMask = 0xFF000000
} ;