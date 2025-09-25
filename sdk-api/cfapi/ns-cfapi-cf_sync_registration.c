typedef struct CF_SYNC_REGISTRATION {
  ULONG   StructSize;
  LPCWSTR ProviderName;
  LPCWSTR ProviderVersion;
  LPCVOID SyncRootIdentity;
  DWORD   SyncRootIdentityLength;
  LPCVOID FileIdentity;
  DWORD   FileIdentityLength;
  GUID    ProviderId;
} CF_SYNC_REGISTRATION;