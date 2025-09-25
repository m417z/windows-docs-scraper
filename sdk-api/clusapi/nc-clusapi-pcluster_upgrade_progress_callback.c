PCLUSTER_UPGRADE_PROGRESS_CALLBACK PclusterUpgradeProgressCallback;

BOOL PclusterUpgradeProgressCallback(
  PVOID pvCallbackArg,
  CLUSTER_UPGRADE_PHASE eUpgradePhase
)
{...}