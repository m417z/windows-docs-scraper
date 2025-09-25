DWORD DhcpRequestParams(
  [in]      DWORD                 Flags,
  [in]      LPVOID                Reserved,
  [in]      LPWSTR                AdapterName,
  [in]      LPDHCPCAPI_CLASSID    ClassId,
  [in]      DHCPCAPI_PARAMS_ARRAY SendParams,
  [in, out] DHCPCAPI_PARAMS_ARRAY RecdParams,
  [in]      LPBYTE                Buffer,
  [in, out] LPDWORD               pSize,
  [in]      LPWSTR                RequestIdStr
);