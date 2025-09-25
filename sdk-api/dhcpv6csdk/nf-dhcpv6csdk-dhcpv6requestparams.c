DWORD Dhcpv6RequestParams(
  BOOL                    forceNewInform,
  LPVOID                  reserved,
  LPWSTR                  adapterName,
  LPDHCPV6CAPI_CLASSID    classId,
  DHCPV6CAPI_PARAMS_ARRAY recdParams,
  LPBYTE                  buffer,
  LPDWORD                 pSize
);