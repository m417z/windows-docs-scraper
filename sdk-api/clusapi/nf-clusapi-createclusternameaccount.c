DWORD CreateClusterNameAccount(
  [in]           HCLUSTER                         hCluster,
  [in]           PCREATE_CLUSTER_NAME_ACCOUNT     pConfig,
  [in, optional] PCLUSTER_SETUP_PROGRESS_CALLBACK pfnProgressCallback,
  [in, optional] PVOID                            pvCallbackArg
);