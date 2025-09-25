STRSAFEAPI StringCbVPrintf_lExW(
  [out]           STRSAFE_LPWSTR                                  pszDest,
  [in]            size_t                                          cbDest,
  [out]           STRSAFE_LPWSTR                                  *ppszDestEnd,
  [out, optional] size_t                                          *pcbRemaining,
  [in]            DWORD                                           dwFlags,
  [in]            _Printf_format_string_params_(2)STRSAFE_LPCWSTR pszFormat,
  [in]            _locale_t                                       locale,
  [in]            va_list                                         argList
);