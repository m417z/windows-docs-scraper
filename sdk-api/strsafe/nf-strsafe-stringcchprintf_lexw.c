STRSAFEAPI StringCchPrintf_lExW(
  [out]           STRSAFE_LPWSTR                                  pszDest,
  [in]            size_t                                          cchDest,
  [out]           STRSAFE_LPWSTR                                  *ppszDestEnd,
  [out, optional] size_t                                          *pcchRemaining,
  [in]            DWORD                                           dwFlags,
  [in]            _Printf_format_string_params_(2)STRSAFE_LPCWSTR pszFormat,
  [in]            _locale_t                                       locale,
                  ...                                             
);