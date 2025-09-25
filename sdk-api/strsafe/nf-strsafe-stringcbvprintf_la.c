STRSAFEAPI StringCbVPrintf_lA(
  [out] STRSAFE_LPSTR                                  pszDest,
  [in]  size_t                                         cbDest,
  [in]  _Printf_format_string_params_(2)STRSAFE_LPCSTR pszFormat,
  [in]  _locale_t                                      locale,
  [in]  va_list                                        argList
);