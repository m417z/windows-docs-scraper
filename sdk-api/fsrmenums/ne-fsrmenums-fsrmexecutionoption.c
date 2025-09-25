typedef enum _FsrmExecutionOption {
  FsrmExecutionOption_Unknown = 0,
  FsrmExecutionOption_EvaluateUnset = 1,
  FsrmExecutionOption_ReEvaluate_ConsiderExistingValue = 2,
  FsrmExecutionOption_ReEvaluate_IgnoreExistingValue = 3
} FsrmExecutionOption;