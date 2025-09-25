WMI_QUERY_REGINFO_CALLBACK WmiQueryReginfoCallback;

NTSTATUS WmiQueryReginfoCallback(
  [in]  PDEVICE_OBJECT DeviceObject,
  [out] PULONG RegFlags,
  [out] PUNICODE_STRING InstanceName,
  [out] PUNICODE_STRING *RegistryPath,
  [out] PUNICODE_STRING MofResourceName,
  [out] PDEVICE_OBJECT *Pdo
)
{...}