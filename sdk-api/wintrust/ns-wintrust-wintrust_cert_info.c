typedef struct WINTRUST_CERT_INFO_ {
  DWORD        cbStruct;
  LPCWSTR      pcwszDisplayName;
  CERT_CONTEXT *psCertContext;
  DWORD        chStores;
  HCERTSTORE   *pahStores;
  DWORD        dwFlags;
  FILETIME     *psftVerifyAsOf;
} WINTRUST_CERT_INFO, *PWINTRUST_CERT_INFO;