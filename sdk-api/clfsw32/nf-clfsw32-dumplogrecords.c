CLFSUSER_API BOOL DumpLogRecords(
  [in]           PWSTR                     pwszLogFileName,
  [in]           CLFS_RECORD_TYPE          fRecordType,
  [in, optional] PCLFS_LSN                 plsnStart,
  [in, optional] PCLFS_LSN                 plsnEnd,
  [in, optional] PFILE                     pstrmOut,
  [in, optional] CLFS_PRINT_RECORD_ROUTINE pfnPrintRecord,
  [in, optional] CLFS_BLOCK_ALLOCATION     pfnAllocBlock,
  [in, optional] CLFS_BLOCK_DEALLOCATION   pfnFreeBlock,
  [in, optional] PVOID                     pvBlockAllocContext,
  [in]           ULONG                     cbBlock,
  [in]           ULONG                     cMaxBlocks
);