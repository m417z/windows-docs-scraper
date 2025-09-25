typedef struct _CRYPTUI_WIZ_EXPORT_CERTCONTEXT_INFO {
  DWORD   dwSize;
  DWORD   dwExportFormat;
  BOOL    fExportChain;
  BOOL    fExportPrivateKeys;
  LPCWSTR pwszPassword;
  BOOL    fStrongEncryption;
} CRYPTUI_WIZ_EXPORT_CERTCONTEXT_INFO, *PCRYPTUI_WIZ_EXPORT_CERTCONTEXT_INFO;