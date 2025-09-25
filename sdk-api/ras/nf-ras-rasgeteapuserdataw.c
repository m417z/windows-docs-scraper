DWORD RasGetEapUserDataW(
  [in]      HANDLE  hToken,
  [in]      LPCWSTR pszPhonebook,
  [in]      LPCWSTR pszEntry,
  [out]     BYTE    *pbEapData,
  [in, out] DWORD   *pdwSizeofEapData
);