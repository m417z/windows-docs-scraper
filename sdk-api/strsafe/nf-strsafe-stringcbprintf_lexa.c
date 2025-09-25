STRSAFEAPI StringCbPrintf_lExA(
  [out]           STRSAFE_LPSTR                                  pszDest,
  [in]            size_t                                         cbDest,
  [out]           STRSAFE_LPSTR                                  *ppszDestEnd,
  [out, optional] size_t                                         *pcbRemaining,
  [in]            DWORD                                          dwFlags,
  [in]            _Printf_format_string_params_(2)STRSAFE_LPCSTR pszFormat,
  [in]            _locale_t                                      locale,
                  ...                                            
);