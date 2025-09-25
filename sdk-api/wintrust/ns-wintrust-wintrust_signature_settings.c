typedef struct WINTRUST_SIGNATURE_SETTINGS_ {
  DWORD                  cbStruct;
  DWORD                  dwIndex;
  DWORD                  dwFlags;
  DWORD                  cSecondarySigs;
  DWORD                  dwVerifiedSigIndex;
  PCERT_STRONG_SIGN_PARA pCryptoPolicy;
} WINTRUST_SIGNATURE_SETTINGS, *PWINTRUST_SIGNATURE_SETTINGS;