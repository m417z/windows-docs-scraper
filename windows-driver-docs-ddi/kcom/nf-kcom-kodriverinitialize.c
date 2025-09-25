COMDDKAPI NTSTATUS KoDriverInitialize(
  [in] PDRIVER_OBJECT        DriverObject,
  [in] PUNICODE_STRING       RegistryPathName,
  [in] KoCreateObjectHandler CreateObjectHandler
);