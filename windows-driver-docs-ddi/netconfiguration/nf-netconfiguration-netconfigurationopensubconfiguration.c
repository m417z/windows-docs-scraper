NTSTATUS NetConfigurationOpenSubConfiguration(
  [_In_]     NETCONFIGURATION      Configuration,
  [_In_]     PCUNICODE_STRING      SubConfigurationName,
  [_In_opt_] WDF_OBJECT_ATTRIBUTES *SubConfigurationAttributes,
  [_Out_]    NETCONFIGURATION      *SubConfiguration
);