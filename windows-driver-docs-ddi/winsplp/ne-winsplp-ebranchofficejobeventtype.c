typedef enum {
  kInvalidJobState,
  kLogJobPrinted,
  kLogJobRendered,
  kLogJobError,
  kLogJobPipelineError,
  kLogOfflineFileFull
} EBranchOfficeJobEventType;