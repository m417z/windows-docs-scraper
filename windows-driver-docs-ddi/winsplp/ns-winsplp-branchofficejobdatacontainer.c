typedef struct {
  DWORD               cJobDataEntries;
  BranchOfficeJobData JobData[1];
} BranchOfficeJobDataContainer, *PBranchOfficeJobDataContainer, *LPBranchOfficeJobDataContainer;