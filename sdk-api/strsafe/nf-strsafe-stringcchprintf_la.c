STRSAFEAPI StringCchPrintf_lA(
  [out] STRSAFE_LPSTR                                  pszDest,
  [in]  size_t                                         cchDest,
  [in]  _Printf_format_string_params_(2)STRSAFE_LPCSTR pszFormat,
  [in]  _locale_t                                      locale,
        ...                                            
);