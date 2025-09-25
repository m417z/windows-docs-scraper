NTSTATUS AuxKlibEnumerateSystemFirmwareTables(
  [in]            ULONG  FirmwareTableProviderSignature,
  [out, optional] PVOID  FirmwareTableBuffer,
  [in]            ULONG  BufferLength,
  [out, optional] PULONG ReturnLength
);