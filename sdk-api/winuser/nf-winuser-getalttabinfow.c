BOOL GetAltTabInfoW(
  [in, optional]  HWND        hwnd,
  [in]            int         iItem,
  [in, out]       PALTTABINFO pati,
  [out, optional] LPWSTR      pszItemText,
  [in]            UINT        cchItemText
);