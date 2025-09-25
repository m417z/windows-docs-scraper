typedef enum WICNamedWhitePoint {
  WICWhitePointDefault = 0x1,
  WICWhitePointDaylight = 0x2,
  WICWhitePointCloudy = 0x4,
  WICWhitePointShade = 0x8,
  WICWhitePointTungsten = 0x10,
  WICWhitePointFluorescent = 0x20,
  WICWhitePointFlash = 0x40,
  WICWhitePointUnderwater = 0x80,
  WICWhitePointCustom = 0x100,
  WICWhitePointAutoWhiteBalance = 0x200,
  WICWhitePointAsShot,
  WICNAMEDWHITEPOINT_FORCE_DWORD = 0x7fffffff
} ;