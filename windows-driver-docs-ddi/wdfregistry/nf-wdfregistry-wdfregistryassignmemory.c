NTSTATUS WdfRegistryAssignMemory(
  [in]           WDFKEY            Key,
  [in]           PCUNICODE_STRING  ValueName,
  [in]           ULONG             ValueType,
  [in]           WDFMEMORY         Memory,
  [in, optional] PWDFMEMORY_OFFSET MemoryOffsets
);