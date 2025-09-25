int ToUnicode(
  [in]           UINT       wVirtKey,
  [in]           UINT       wScanCode,
  [in, optional] const BYTE *lpKeyState,
  [out]          LPWSTR     pwszBuff,
  [in]           int        cchBuff,
  [in]           UINT       wFlags
);