DWORD RasGetEapUserDataA(
  [in]      HANDLE hToken,
  [in]      LPCSTR pszPhonebook,
  [in]      LPCSTR pszEntry,
  [out]     BYTE   *pbEapData,
  [in, out] DWORD  *pdwSizeofEapData
);