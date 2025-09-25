typedef struct tagCOMPOSITION_TARGET_ID {
  bool operator==(
    const tagCOMPOSITION_TARGET_ID & rhs
  );
  bool operator!=(
    const tagCOMPOSITION_TARGET_ID & rhs
  );
  LUID displayAdapterLuid;
  LUID renderAdapterLuid;
  UINT vidPnSourceId;
  UINT vidPnTargetId;
  UINT uniqueId;
} COMPOSITION_TARGET_ID;