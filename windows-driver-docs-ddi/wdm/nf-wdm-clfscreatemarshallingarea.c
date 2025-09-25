CLFSUSER_API NTSTATUS ClfsCreateMarshallingArea(
  [in]           PLOG_FILE_OBJECT   plfoLog,
  [in]           POOL_TYPE          ePoolType,
  [in, optional] PALLOCATE_FUNCTION pfnAllocBuffer,
  [in, optional] PFREE_FUNCTION     pfnFreeBuffer,
  [in]           ULONG              cbMarshallingBuffer,
  [in]           ULONG              cMaxWriteBuffers,
  [in]           ULONG              cMaxReadBuffers,
  [out]          PVOID              *ppvMarshalContext
);