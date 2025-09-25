NTSTATUS WdfMemoryCreate(
  [in, optional]  PWDF_OBJECT_ATTRIBUTES Attributes,
  [in]            POOL_TYPE              PoolType,
  [in, optional]  ULONG                  PoolTag,
  [in]            size_t                 BufferSize,
  [out]           WDFMEMORY              *Memory,
  [out, optional] PVOID                  *Buffer
);