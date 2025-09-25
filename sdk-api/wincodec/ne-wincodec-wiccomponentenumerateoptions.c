typedef enum WICComponentEnumerateOptions {
  WICComponentEnumerateDefault = 0,
  WICComponentEnumerateRefresh = 0x1,
  WICComponentEnumerateDisabled = 0x80000000,
  WICComponentEnumerateUnsigned = 0x40000000,
  WICComponentEnumerateBuiltInOnly = 0x20000000,
  WICCOMPONENTENUMERATEOPTIONS_FORCE_DWORD = 0x7fffffff
} ;