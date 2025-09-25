HRESULT NET_API_FUNCTION NetGetAadJoinInformation(
  [in, optional] LPCWSTR          pcszTenantId,
  [out]          PDSREG_JOIN_INFO *ppJoinInfo
);