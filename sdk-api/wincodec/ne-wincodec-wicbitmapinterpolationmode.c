typedef enum WICBitmapInterpolationMode {
  WICBitmapInterpolationModeNearestNeighbor = 0,
  WICBitmapInterpolationModeLinear = 0x1,
  WICBitmapInterpolationModeCubic = 0x2,
  WICBitmapInterpolationModeFant = 0x3,
  WICBitmapInterpolationModeHighQualityCubic = 0x4,
  WICBITMAPINTERPOLATIONMODE_FORCE_DWORD = 0x7fffffff
} ;