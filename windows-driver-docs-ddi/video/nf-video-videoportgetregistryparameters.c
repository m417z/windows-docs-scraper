VIDEOPORT_API VP_STATUS VideoPortGetRegistryParameters(
       PVOID                          HwDeviceExtension,
  [in] PWSTR                          ParameterName,
       UCHAR                          IsParameterFileName,
       PMINIPORT_GET_REGISTRY_ROUTINE GetRegistryRoutine,
       PVOID                          Context
);