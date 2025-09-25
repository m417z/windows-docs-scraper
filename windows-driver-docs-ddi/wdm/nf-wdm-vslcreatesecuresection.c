NTSTATUS VslCreateSecureSection(
  PHANDLE   Handle,
  PEPROCESS TargetProcess,
  PMDL      Mdl,
  ULONG     DevicePageProtection,
  ULONG     Attributes
);