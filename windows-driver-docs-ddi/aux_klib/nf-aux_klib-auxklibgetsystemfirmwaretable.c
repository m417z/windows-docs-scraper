NTSTATUS AuxKlibGetSystemFirmwareTable(
  [in]            ULONG  FirmwareTableProviderSignature,
  [in]            ULONG  FirmwareTableID,
  [out, optional] PVOID  FirmwareTableBuffer,
  [in]            ULONG  BufferLength,
  [out, optional] PULONG ReturnLength
);