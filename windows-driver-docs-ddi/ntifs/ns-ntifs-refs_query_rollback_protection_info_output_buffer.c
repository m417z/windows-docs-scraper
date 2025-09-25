typedef struct _REFS_QUERY_ROLLBACK_PROTECTION_INFO_OUTPUT_BUFFER {
  ULONG     Version;
  GUID      VolumeGuid;
  GUID      RollbackProtectionGuid;
  BOOLEAN   FailMountOnMismatch;
  ULONGLONG FrozenVirtualClock;
  ULONGLONG CurrentVirtualClock;
  USHORT    ChecksumType;
  ULONG     ChecksumLength;
  ULONG     ChecksumOffset;
  ULONG     CustomPayloadLength;
  ULONG     CustomPayloadOffset;
} REFS_QUERY_ROLLBACK_PROTECTION_INFO_OUTPUT_BUFFER, *PREFS_QUERY_ROLLBACK_PROTECTION_INFO_OUTPUT_BUFFER;