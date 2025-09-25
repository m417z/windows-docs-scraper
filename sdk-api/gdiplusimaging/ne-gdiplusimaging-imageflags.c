typedef enum ImageFlags {
  ImageFlagsNone = 0,
  ImageFlagsScalable = 0x0001,
  ImageFlagsHasAlpha = 0x0002,
  ImageFlagsHasTranslucent = 0x0004,
  ImageFlagsPartiallyScalable = 0x0008,
  ImageFlagsColorSpaceRGB = 0x0010,
  ImageFlagsColorSpaceCMYK = 0x0020,
  ImageFlagsColorSpaceGRAY = 0x0040,
  ImageFlagsColorSpaceYCBCR = 0x0080,
  ImageFlagsColorSpaceYCCK = 0x0100,
  ImageFlagsHasRealDPI = 0x1000,
  ImageFlagsHasRealPixelSize = 0x2000,
  ImageFlagsReadOnly = 0x00010000,
  ImageFlagsCaching = 0x00020000
} ;