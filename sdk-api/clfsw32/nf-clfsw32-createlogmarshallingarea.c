CLFSUSER_API BOOL CreateLogMarshallingArea(
  [in]           HANDLE                  hLog,
  [in, optional] CLFS_BLOCK_ALLOCATION   pfnAllocBuffer,
  [in, optional] CLFS_BLOCK_DEALLOCATION pfnFreeBuffer,
  [in, optional] PVOID                   pvBlockAllocContext,
  [in]           ULONG                   cbMarshallingBuffer,
  [in]           ULONG                   cMaxWriteBuffers,
  [in]           ULONG                   cMaxReadBuffers,
  [out]          PVOID                   *ppvMarshal
);