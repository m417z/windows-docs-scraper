NET_API_STATUS NET_API_FUNCTION NetGetJoinInformation(
  [in]  LPCWSTR               lpServer,
  [out] LPWSTR                *lpNameBuffer,
  [out] PNETSETUP_JOIN_STATUS BufferType
);