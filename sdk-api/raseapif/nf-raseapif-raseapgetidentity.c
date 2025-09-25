DWORD RasEapGetIdentity(
  [in]  DWORD   dwEapTypeId,
  [in]  HWND    hwndParent,
  [in]  DWORD   dwFlags,
  [in]  LPCWSTR pwszPhonebook,
  [in]  LPCWSTR pwszEntry,
  [in]  BYTE    *pConnectionDataIn,
  [in]  DWORD   dwSizeOfConnectionDataIn,
  [in]  BYTE    *pUserDataIn,
  [in]  DWORD   dwSizeOfUserDataIn,
  [out] BYTE    **ppUserDataOut,
  [out] DWORD   *pdwSizeOfUserDataOut,
  [out] LPWSTR  *ppwszIdentityOut
);