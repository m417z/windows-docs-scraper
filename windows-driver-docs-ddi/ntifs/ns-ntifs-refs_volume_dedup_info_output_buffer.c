typedef struct _REFS_VOLUME_DEDUP_INFO_OUTPUT_BUFFER {
  ULONG   Version;
  BOOLEAN Enabled;
  BOOLEAN EnabledWeakRef;
  BOOLEAN EnabledDirtyRangeTracking;
  BOOLEAN WeakRefInconsistent;
  BOOLEAN IsClustered;
  ULONG   VolumeIdHash;
  GUID    VolumeGuid;
  GUID    VolumeUniqueGuid;
} REFS_VOLUME_DEDUP_INFO_OUTPUT_BUFFER, *PREFS_VOLUME_DEDUP_INFO_OUTPUT_BUFFER;