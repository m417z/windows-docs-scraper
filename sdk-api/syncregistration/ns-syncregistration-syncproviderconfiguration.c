typedef struct _SyncProviderConfiguration {
  DWORD dwVersion;
  GUID  guidInstanceId;
  CLSID clsidProvider;
  GUID  guidConfigUIInstanceId;
  GUID  guidContentType;
  DWORD dwCapabilities;
  DWORD dwSupportedArchitecture;
} SyncProviderConfiguration;