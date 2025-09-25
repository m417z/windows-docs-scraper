VOID WDF_IO_TARGET_OPEN_PARAMS_INIT_CREATE_BY_NAME(
  [out] PWDF_IO_TARGET_OPEN_PARAMS Params,
  [in]  PCUNICODE_STRING           TargetDeviceName,
  [in]  ACCESS_MASK                DesiredAccess
);