NTSTATUS WdfDriverCreate(
  [in]            PDRIVER_OBJECT         DriverObject,
  [in]            PCUNICODE_STRING       RegistryPath,
  [in, optional]  PWDF_OBJECT_ATTRIBUTES DriverAttributes,
  [in]            PWDF_DRIVER_CONFIG     DriverConfig,
  [out, optional] WDFDRIVER              *Driver
);