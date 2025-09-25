PCLUSTER_SETUP_PROGRESS_CALLBACK PclusterSetupProgressCallback;

BOOL PclusterSetupProgressCallback(
  [in, optional] PVOID pvCallbackArg,
  [in]           CLUSTER_SETUP_PHASE eSetupPhase,
  [in]           CLUSTER_SETUP_PHASE_TYPE ePhaseType,
  [in]           CLUSTER_SETUP_PHASE_SEVERITY ePhaseSeverity,
  [in]           DWORD dwPercentComplete,
  [in, optional] PCWSTR lpszObjectName,
  [in] [in]      DWORD dwStatus
)
{...}