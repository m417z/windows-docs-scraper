typedef struct APPX_ENCRYPTED_PACKAGE_SETTINGS {
  UINT32  keyLength;
  LPCWSTR encryptionAlgorithm;
  BOOL    useDiffusion;
  IUri    *blockMapHashAlgorithm;
} APPX_ENCRYPTED_PACKAGE_SETTINGS;