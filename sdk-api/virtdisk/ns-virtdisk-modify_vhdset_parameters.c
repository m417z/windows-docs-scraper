typedef struct _MODIFY_VHDSET_PARAMETERS {
  MODIFY_VHDSET_VERSION Version;
  union {
    struct {
      GUID   SnapshotId;
      PCWSTR SnapshotFilePath;
    } SnapshotPath;
    GUID   SnapshotId;
    PCWSTR DefaultFilePath;
  };
} MODIFY_VHDSET_PARAMETERS, *PMODIFY_VHDSET_PARAMETERS;