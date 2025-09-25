NTSTATUS USBD_GetPdoRegistryParameter(
  [in]      PDEVICE_OBJECT PhysicalDeviceObject,
  [in, out] PVOID          Parameter,
  [in]      ULONG          ParameterLength,
  [in]      PWSTR          KeyName,
  [in]      ULONG          KeyNameLength
);