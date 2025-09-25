NTSTATUS NetConfigurationQueryUlong(
  [_In_]  NETCONFIGURATION                    Configuration,
  [_In_]  NET_CONFIGURATION_QUERY_ULONG_FLAGS Flags,
  [_In_]  PCUNICODE_STRING                    ValueName,
  [_Out_] ULONG                               *Value
);