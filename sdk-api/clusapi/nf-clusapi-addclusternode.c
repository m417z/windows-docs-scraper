HNODE AddClusterNode(
  [in]           HCLUSTER                         hCluster,
  [in]           PCWSTR                           lpszNodeName,
  [in, optional] PCLUSTER_SETUP_PROGRESS_CALLBACK pfnProgressCallback,
  [in, optional] PVOID                            pvCallbackArg
);