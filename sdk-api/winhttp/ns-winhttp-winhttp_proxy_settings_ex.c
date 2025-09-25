typedef struct _WINHTTP_PROXY_SETTINGS_EX {
  ULONGLONG ullGenerationId;
  ULONGLONG ullFlags;
  PCWSTR    pcwszAutoconfigUrl;
  PCWSTR    pcwszProxy;
  PCWSTR    pcwszSecureProxy;
  DWORD     cProxyBypasses;
  PCWSTR    *rgpcwszProxyBypasses;
  DWORD     dwInterfaceIndex;
  PCWSTR    pcwszConnectionName;
} WINHTTP_PROXY_SETTINGS_EX, *PWINHTTP_PROXY_SETTINGS_EX;