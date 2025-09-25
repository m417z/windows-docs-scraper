NTSTATUS ExGetFirmwareEnvironmentVariable(
  [in]            PUNICODE_STRING VariableName,
  [in]            LPGUID          VendorGuid,
  [out, optional] PVOID           Value,
  [in, out]       PULONG          ValueLength,
  [out, optional] PULONG          Attributes
);