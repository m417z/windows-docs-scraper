typedef enum WICRawRotationCapabilities {
  WICRawRotationCapabilityNotSupported = 0,
  WICRawRotationCapabilityGetSupported = 0x1,
  WICRawRotationCapabilityNinetyDegreesSupported = 0x2,
  WICRawRotationCapabilityFullySupported = 0x3,
  WICRAWROTATIONCAPABILITIES_FORCE_DWORD = 0x7fffffff
} ;