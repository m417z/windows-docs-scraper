typedef enum _FsrmGetFilePropertyOptions {
  FsrmGetFilePropertyOptions_None = 0,
  FsrmGetFilePropertyOptions_NoRuleEvaluation = 0x1,
  FsrmGetFilePropertyOptions_Persistent = 0x2,
  FsrmGetFilePropertyOptions_FailOnPersistErrors = 0x4,
  FsrmGetFilePropertyOptions_SkipOrphaned = 0x8
} FsrmGetFilePropertyOptions;