NTSTATUS WdfRegistryQueryMemory(
  [in]            WDFKEY                 Key,
  [in]            PCUNICODE_STRING       ValueName,
  [in]            POOL_TYPE              PoolType,
  [in, optional]  PWDF_OBJECT_ATTRIBUTES MemoryAttributes,
  [out]           WDFMEMORY              *Memory,
  [out, optional] PULONG                 ValueType
);