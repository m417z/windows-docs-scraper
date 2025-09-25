NTSTATUS ExSetFirmwareEnvironmentVariable(
  [in] PUNICODE_STRING VariableName,
  [in] LPGUID          VendorGuid,
  [in] PVOID           Value,
  [in] ULONG           ValueLength,
  [in] ULONG           Attributes
);