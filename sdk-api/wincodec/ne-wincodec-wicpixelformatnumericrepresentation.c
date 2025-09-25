typedef enum WICPixelFormatNumericRepresentation {
  WICPixelFormatNumericRepresentationUnspecified = 0,
  WICPixelFormatNumericRepresentationIndexed = 0x1,
  WICPixelFormatNumericRepresentationUnsignedInteger = 0x2,
  WICPixelFormatNumericRepresentationSignedInteger = 0x3,
  WICPixelFormatNumericRepresentationFixed = 0x4,
  WICPixelFormatNumericRepresentationFloat = 0x5,
  WICPixelFormatNumericRepresentation_FORCE_DWORD = 0x7fffffff
} ;