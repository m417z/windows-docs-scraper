NTSTATUS FsRtlRegisterUncProviderEx(
  [out] PHANDLE                  MupHandle,
  [in]  PCUNICODE_STRING         RedirDevName,
  [in]  PDEVICE_OBJECT           DeviceObject,
  [in]  FSRTL_UNC_PROVIDER_FLAGS Flags
);