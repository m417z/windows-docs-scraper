int ToAsciiEx(
  [in]           UINT       uVirtKey,
  [in]           UINT       uScanCode,
  [in, optional] const BYTE *lpKeyState,
  [out]          LPWORD     lpChar,
  [in]           UINT       uFlags,
  [in, optional] HKL        dwhkl
);