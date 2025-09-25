KSDDKAPI NTSTATUS KsMapModuleName(
  [in]  PDEVICE_OBJECT  PhysicalDeviceObject,
  [in]  PUNICODE_STRING ModuleName,
  [out] PUNICODE_STRING ImageName,
  [out] PULONG_PTR      ResourceId,
  [out] PULONG          ValueType
);