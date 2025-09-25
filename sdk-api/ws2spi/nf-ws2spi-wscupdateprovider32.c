int WSCUpdateProvider32(
  [in]  LPGUID                    lpProviderId,
  [in]  const WCHAR               *lpszProviderDllPath,
  [in]  const LPWSAPROTOCOL_INFOW lpProtocolInfoList,
  [in]  DWORD                     dwNumberOfEntries,
  [out] LPINT                     lpErrno
);