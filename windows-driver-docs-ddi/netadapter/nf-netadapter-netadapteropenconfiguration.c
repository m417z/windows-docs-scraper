NTSTATUS NetAdapterOpenConfiguration(
  [_In_]     NETADAPTER            Adapter,
  [_In_opt_] WDF_OBJECT_ATTRIBUTES *ConfigurationAttributes,
  [_Out_]    NETCONFIGURATION      *Configuration
);