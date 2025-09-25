typedef struct _SyncProviderConfigUIConfiguration {
  DWORD dwVersion;
  GUID  guidInstanceId;
  CLSID clsidConfigUI;
  GUID  guidContentType;
  DWORD dwCapabilities;
  DWORD dwSupportedArchitecture;
  BOOL  fIsGlobal;
} SyncProviderConfigUIConfiguration;