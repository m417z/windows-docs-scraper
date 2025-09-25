typedef struct {
  EBranchOfficeJobEventType eEventType;
  DWORD                     JobId;
  union {
    BranchOfficeJobDataPrinted        LogJobPrinted;
    BranchOfficeJobDataRendered       LogJobRendered;
    BranchOfficeJobDataError          LogJobError;
    BranchOfficeJobDataPipelineFailed LogPipelineFailed;
    BranchOfficeLogOfflineFileFull    LogOfflineFileFull;
  } JobInfo;
} BranchOfficeJobData, *PBranchOfficeJobData;