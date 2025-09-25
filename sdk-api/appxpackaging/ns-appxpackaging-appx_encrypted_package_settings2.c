typedef struct APPX_ENCRYPTED_PACKAGE_SETTINGS2 {
  UINT32  keyLength;
  LPCWSTR encryptionAlgorithm;
  IUri    *blockMapHashAlgorithm;
  DWORD   options;
} APPX_ENCRYPTED_PACKAGE_SETTINGS2;