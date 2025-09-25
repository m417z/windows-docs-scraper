typedef struct tagOSUpdateAssessment {
  BOOL                   isEndOfSupport;
  UpdateAssessment       assessmentForCurrent;
  UpdateAssessment       assessmentForUpToDate;
  UpdateAssessmentStatus securityStatus;
  FILETIME               assessmentTime;
  FILETIME               releaseInfoTime;
  LPWSTR                 currentOSBuild;
  FILETIME               currentOSReleaseTime;
  LPWSTR                 upToDateOSBuild;
  FILETIME               upToDateOSReleaseTime;
} OSUpdateAssessment;