typedef enum ImageCodecFlags {
  ImageCodecFlagsEncoder = 0x00000001,
  ImageCodecFlagsDecoder = 0x00000002,
  ImageCodecFlagsSupportBitmap = 0x00000004,
  ImageCodecFlagsSupportVector = 0x00000008,
  ImageCodecFlagsSeekableEncode = 0x00000010,
  ImageCodecFlagsBlockingDecode = 0x00000020,
  ImageCodecFlagsBuiltin = 0x00010000,
  ImageCodecFlagsSystem = 0x00020000,
  ImageCodecFlagsUser = 0x00040000
} ;