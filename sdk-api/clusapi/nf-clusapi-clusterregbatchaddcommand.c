LONG ClusterRegBatchAddCommand(
  [in]           HREGBATCH           hRegBatch,
  [in]           CLUSTER_REG_COMMAND dwCommand,
  [in, optional] LPCWSTR             wzName,
  [in]           DWORD               dwOptions,
  [in, optional] VOID const          *lpData,
  [in]           DWORD               cbData
);