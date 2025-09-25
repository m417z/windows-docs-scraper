DWORD DestroyCluster(
  [in]           HCLUSTER                         hCluster,
  [in, optional] PCLUSTER_SETUP_PROGRESS_CALLBACK pfnProgressCallback,
  [in, optional] PVOID                            pvCallbackArg,
  [in]           BOOL                             fdeleteVirtualComputerObjects
);