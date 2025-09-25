NTSTATUS NetConfigurationQueryBinary(
  [_In_]     NETCONFIGURATION      Configuration,
  [_In_]     PCUNICODE_STRING      ValueName,
  [_In_]     POOL_TYPE             PoolType,
  [_In_opt_] WDF_OBJECT_ATTRIBUTES *MemoryAttributes,
  [_Out_]    WDFMEMORY             *Memory
);