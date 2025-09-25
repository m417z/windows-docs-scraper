typedef struct _REFS_VOLUME_DEDUP_INFO_INPUT_BUFFER {
  ULONG   Version;
  BOOLEAN SetDedupState;
  BOOLEAN Enable;
  BOOLEAN SetWeakRefState;
  BOOLEAN EnableWeakRef;
  BOOLEAN SetDirtyRangeTrackingState;
  BOOLEAN EnableDirtyRangeTracking;
  BOOLEAN SetWeakRefInconsistentState;
  BOOLEAN SetWeakRefInconsistent;
} REFS_VOLUME_DEDUP_INFO_INPUT_BUFFER, *PREFS_VOLUME_DEDUP_INFO_INPUT_BUFFER;