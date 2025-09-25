NTSTATUS WdfRegistryAssignValue(
  [in] WDFKEY           Key,
  [in] PCUNICODE_STRING ValueName,
  [in] ULONG            ValueType,
  [in] ULONG            ValueLength,
  [in] PVOID            Value
);