STRSAFEAPI StringCchPrintf_lW(
  [out] STRSAFE_LPWSTR                                  pszDest,
  [in]  size_t                                          cchDest,
  [in]  _Printf_format_string_params_(2)STRSAFE_LPCWSTR pszFormat,
  [in]  _locale_t                                       locale,
        ...                                             
);