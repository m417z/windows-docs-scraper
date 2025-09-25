int ToUnicodeEx(
  [in]           UINT       wVirtKey,
  [in]           UINT       wScanCode,
  [in]           const BYTE *lpKeyState,
  [out]          LPWSTR     pwszBuff,
  [in]           int        cchBuff,
  [in]           UINT       wFlags,
  [in, optional] HKL        dwhkl
);