CLFSUSER_API NTSTATUS ClfsCreateMarshallingAreaEx(
  PLOG_FILE_OBJECT   plfoLog,
  POOL_TYPE          ePoolType,
  PALLOCATE_FUNCTION pfnAllocBuffer,
  PFREE_FUNCTION     pfnFreeBuffer,
  ULONG              cbMarshallingBuffer,
  ULONG              cMaxWriteBuffers,
  ULONG              cMaxReadBuffers,
  ULONG              cAlignmentSize,
  ULONGLONG          fFlags,
  PVOID              *ppvMarshalContext
);