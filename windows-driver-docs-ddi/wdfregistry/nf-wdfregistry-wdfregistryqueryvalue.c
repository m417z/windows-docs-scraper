NTSTATUS WdfRegistryQueryValue(
  [in]            WDFKEY           Key,
  [in]            PCUNICODE_STRING ValueName,
  [in]            ULONG            ValueLength,
  [out, optional] PVOID            Value,
  [out, optional] PULONG           ValueLengthQueried,
  [out, optional] PULONG           ValueType
);