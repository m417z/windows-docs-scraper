typedef enum WICTiffCompressionOption {
  WICTiffCompressionDontCare = 0,
  WICTiffCompressionNone = 0x1,
  WICTiffCompressionCCITT3 = 0x2,
  WICTiffCompressionCCITT4 = 0x3,
  WICTiffCompressionLZW = 0x4,
  WICTiffCompressionRLE = 0x5,
  WICTiffCompressionZIP = 0x6,
  WICTiffCompressionLZWHDifferencing = 0x7,
  WICTIFFCOMPRESSIONOPTION_FORCE_DWORD = 0x7fffffff
} ;