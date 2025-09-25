DPAPI_IMP BOOL CryptUpdateProtectedState(
  [in]  PSID    pOldSid,
  [in]  LPCWSTR pwszOldPassword,
  [in]  DWORD   dwFlags,
  [out] DWORD   *pdwSuccessCount,
  [out] DWORD   *pdwFailureCount
);