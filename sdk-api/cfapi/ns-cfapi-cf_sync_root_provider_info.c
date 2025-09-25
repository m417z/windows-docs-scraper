typedef struct CF_SYNC_ROOT_PROVIDER_INFO {
  CF_SYNC_PROVIDER_STATUS ProviderStatus;
  WCHAR                   ProviderName[CF_MAX_PROVIDER_NAME_LENGTH + 1];
  WCHAR                   ProviderVersion[CF_MAX_PROVIDER_VERSION_LENGTH + 1];
} CF_SYNC_ROOT_PROVIDER_INFO;