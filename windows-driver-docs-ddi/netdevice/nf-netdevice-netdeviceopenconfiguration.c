NTSTATUS NetDeviceOpenConfiguration(
  [_In_]     WDFDEVICE             Device,
  [_In_opt_] WDF_OBJECT_ATTRIBUTES *ConfigurationAttributes,
  [_Out_]    NETCONFIGURATION      *Configuration
);