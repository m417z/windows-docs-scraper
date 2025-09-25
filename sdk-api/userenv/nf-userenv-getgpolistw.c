USERENVAPI BOOL GetGPOListW(
  [in]  HANDLE                hToken,
  [in]  LPCWSTR               lpName,
  [in]  LPCWSTR               lpHostName,
  [in]  LPCWSTR               lpComputerName,
  [in]  DWORD                 dwFlags,
  [out] PGROUP_POLICY_OBJECTW *pGPOList
);