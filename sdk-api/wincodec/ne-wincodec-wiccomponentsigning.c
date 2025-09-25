typedef enum WICComponentSigning {
  WICComponentSigned = 0x1,
  WICComponentUnsigned = 0x2,
  WICComponentSafe = 0x4,
  WICComponentDisabled = 0x80000000,
  WICCOMPONENTSIGNING_FORCE_DWORD = 0x7fffffff
} ;