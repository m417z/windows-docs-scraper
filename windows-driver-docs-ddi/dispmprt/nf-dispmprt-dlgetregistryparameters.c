VP_STATUS DlGetRegistryParameters(
  PVOID                          DeviceHandle,
  PWSTR                          ParameterName,
  UCHAR                          IsParameterFileName,
  PMINIPORT_GET_REGISTRY_ROUTINE CallbackRoutine,
  PVOID                          Context
);