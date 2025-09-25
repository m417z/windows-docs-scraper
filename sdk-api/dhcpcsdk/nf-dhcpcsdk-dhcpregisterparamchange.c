DWORD DhcpRegisterParamChange(
  [in]      DWORD                 Flags,
  [in]      LPVOID                Reserved,
  [in]      LPWSTR                AdapterName,
  [in]      LPDHCPCAPI_CLASSID    ClassId,
  [in]      DHCPCAPI_PARAMS_ARRAY Params,
  [in, out] LPVOID                Handle
);