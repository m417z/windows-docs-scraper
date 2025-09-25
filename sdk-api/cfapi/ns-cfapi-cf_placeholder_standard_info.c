typedef struct CF_PLACEHOLDER_STANDARD_INFO {
  LARGE_INTEGER    OnDiskDataSize;
  LARGE_INTEGER    ValidatedDataSize;
  LARGE_INTEGER    ModifiedDataSize;
  LARGE_INTEGER    PropertiesSize;
  CF_PIN_STATE     PinState;
  CF_IN_SYNC_STATE InSyncState;
  LARGE_INTEGER    FileId;
  LARGE_INTEGER    SyncRootFileId;
  ULONG            FileIdentityLength;
  BYTE             FileIdentity[1];
} CF_PLACEHOLDER_STANDARD_INFO;