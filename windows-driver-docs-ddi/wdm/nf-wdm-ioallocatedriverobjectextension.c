NTSTATUS IoAllocateDriverObjectExtension(
  [in]  PDRIVER_OBJECT DriverObject,
  [in]  PVOID          ClientIdentificationAddress,
  [in]  ULONG          DriverObjectExtensionSize,
  [out] PVOID          *DriverObjectExtension
);