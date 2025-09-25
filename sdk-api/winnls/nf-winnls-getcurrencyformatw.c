int GetCurrencyFormatW(
  [in]            LCID               Locale,
  [in]            DWORD              dwFlags,
  [in]            LPCWSTR            lpValue,
  [in, optional]  const CURRENCYFMTW *lpFormat,
  [out, optional] LPWSTR             lpCurrencyStr,
  [in]            int                cchCurrency
);