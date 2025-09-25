typedef struct CF_SYNC_ROOT_STANDARD_INFO {
  LARGE_INTEGER           SyncRootFileId;
  CF_HYDRATION_POLICY     HydrationPolicy;
  CF_POPULATION_POLICY    PopulationPolicy;
  CF_INSYNC_POLICY        InSyncPolicy;
  CF_HARDLINK_POLICY      HardLinkPolicy;
  CF_SYNC_PROVIDER_STATUS ProviderStatus;
  WCHAR                   ProviderName[CF_MAX_PROVIDER_NAME_LENGTH + 1];
  WCHAR                   ProviderVersion[CF_MAX_PROVIDER_VERSION_LENGTH + 1];
  ULONG                   SyncRootIdentityLength;
  BYTE                    SyncRootIdentity[1];
} CF_SYNC_ROOT_STANDARD_INFO;