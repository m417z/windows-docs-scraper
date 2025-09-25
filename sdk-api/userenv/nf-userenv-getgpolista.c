USERENVAPI BOOL GetGPOListA(
  [in]  HANDLE                hToken,
  [in]  LPCSTR                lpName,
  [in]  LPCSTR                lpHostName,
  [in]  LPCSTR                lpComputerName,
  [in]  DWORD                 dwFlags,
  [out] PGROUP_POLICY_OBJECTA *pGPOList
);