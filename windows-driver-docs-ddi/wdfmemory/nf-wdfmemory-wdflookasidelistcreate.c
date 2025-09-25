NTSTATUS WdfLookasideListCreate(
  [in, optional] PWDF_OBJECT_ATTRIBUTES LookasideAttributes,
  [in]           size_t                 BufferSize,
  [in]           POOL_TYPE              PoolType,
  [in, optional] PWDF_OBJECT_ATTRIBUTES MemoryAttributes,
  [in, optional] ULONG                  PoolTag,
  [out]          WDFLOOKASIDE           *Lookaside
);