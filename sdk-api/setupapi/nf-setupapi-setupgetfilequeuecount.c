WINSETUPAPI BOOL SetupGetFileQueueCount(
  [in]  HSPFILEQ FileQueue,
  [in]  UINT     SubQueueFileOp,
  [out] PUINT    NumOperations
);