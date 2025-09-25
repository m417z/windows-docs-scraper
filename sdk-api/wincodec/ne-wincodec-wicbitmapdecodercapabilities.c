typedef enum WICBitmapDecoderCapabilities {
  WICBitmapDecoderCapabilitySameEncoder = 0x1,
  WICBitmapDecoderCapabilityCanDecodeAllImages = 0x2,
  WICBitmapDecoderCapabilityCanDecodeSomeImages = 0x4,
  WICBitmapDecoderCapabilityCanEnumerateMetadata = 0x8,
  WICBitmapDecoderCapabilityCanDecodeThumbnail = 0x10,
  WICBITMAPDECODERCAPABILITIES_FORCE_DWORD = 0x7fffffff
} ;