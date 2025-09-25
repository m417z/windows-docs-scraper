NTSTATUS WdfRegistryQueryUnicodeString(
  [in]            WDFKEY           Key,
  [in]            PCUNICODE_STRING ValueName,
  [out, optional] PUSHORT          ValueByteLength,
  [in, out]       PUNICODE_STRING  Value
);