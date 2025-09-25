typedef struct _CRYPTO_SETTINGS {
  eTlsAlgorithmUsage eAlgorithmUsage;
  UNICODE_STRING     strCngAlgId;
  DWORD              cChainingModes;
  PUNICODE_STRING    rgstrChainingModes;
  DWORD              dwMinBitLength;
  DWORD              dwMaxBitLength;
} CRYPTO_SETTINGS, *PCRYPTO_SETTINGS;