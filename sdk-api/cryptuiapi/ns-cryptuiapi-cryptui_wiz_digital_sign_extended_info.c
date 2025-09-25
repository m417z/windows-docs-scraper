typedef struct _CRYPTUI_WIZ_DIGITAL_SIGN_EXTENDED_INFO {
  DWORD             dwSize;
  DWORD             dwAttrFlags;
  LPCWSTR           pwszDescription;
  LPCWSTR           pwszMoreInfoLocation;
  LPCSTR            pszHashAlg;
  LPCWSTR           pwszSigningCertDisplayString;
  HCERTSTORE        hAdditionalCertStore;
  PCRYPT_ATTRIBUTES psAuthenticated;
  PCRYPT_ATTRIBUTES psUnauthenticated;
} CRYPTUI_WIZ_DIGITAL_SIGN_EXTENDED_INFO, *PCRYPTUI_WIZ_DIGITAL_SIGN_EXTENDED_INFO;