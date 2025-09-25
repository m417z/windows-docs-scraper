LONG ClusterRegCloseBatch(
  [in]            HREGBATCH hRegBatch,
  [in]            BOOL      bCommit,
  [out, optional] INT       *failedCommandNumber
);