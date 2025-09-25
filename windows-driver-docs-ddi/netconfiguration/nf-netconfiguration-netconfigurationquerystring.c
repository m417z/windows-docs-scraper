NTSTATUS NetConfigurationQueryString(
  [_In_]     NETCONFIGURATION      Configuration,
  [_In_]     PCUNICODE_STRING      ValueName,
  [_In_opt_] WDF_OBJECT_ATTRIBUTES *StringAttributes,
  [_Out_]    WDFSTRING             *WdfString
);