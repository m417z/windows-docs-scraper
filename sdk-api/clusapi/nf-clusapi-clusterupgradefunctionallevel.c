DWORD ClusterUpgradeFunctionalLevel(
  [in]           HCLUSTER                           hCluster,
  [in]           BOOL                               perform,
  [in, optional] PCLUSTER_UPGRADE_PROGRESS_CALLBACK pfnProgressCallback,
  [in, optional] PVOID                              pvCallbackArg
);