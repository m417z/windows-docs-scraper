typedef enum WICDdsAlphaMode {
  WICDdsAlphaModeUnknown = 0,
  WICDdsAlphaModeStraight = 0x1,
  WICDdsAlphaModePremultiplied = 0x2,
  WICDdsAlphaModeOpaque = 0x3,
  WICDdsAlphaModeCustom = 0x4,
  WICDDSALPHAMODE_FORCE_DWORD = 0x7fffffff
} ;