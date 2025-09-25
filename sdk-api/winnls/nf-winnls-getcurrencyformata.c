int GetCurrencyFormatA(
  [in]            LCID               Locale,
  [in]            DWORD              dwFlags,
  [in]            LPCSTR             lpValue,
  [in, optional]  const CURRENCYFMTA *lpFormat,
  [out, optional] LPSTR              lpCurrencyStr,
  [in]            int                cchCurrency
);