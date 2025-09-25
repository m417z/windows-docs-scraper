STRSAFEAPI StringCbPrintf_lW(
  [out] STRSAFE_LPWSTR                                  pszDest,
  [in]  size_t                                          cbDest,
  [in]  _Printf_format_string_params_(2)STRSAFE_LPCWSTR pszFormat,
  [in]  _locale_t                                       locale,
        ...                                             
);