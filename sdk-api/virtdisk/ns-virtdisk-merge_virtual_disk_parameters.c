typedef struct _MERGE_VIRTUAL_DISK_PARAMETERS {
  MERGE_VIRTUAL_DISK_VERSION Version;
  union {
    struct {
      ULONG MergeDepth;
    } Version1;
    struct {
      ULONG MergeSourceDepth;
      ULONG MergeTargetDepth;
    } Version2;
  };
} MERGE_VIRTUAL_DISK_PARAMETERS, *PMERGE_VIRTUAL_DISK_PARAMETERS;