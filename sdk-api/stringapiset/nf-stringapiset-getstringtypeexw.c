BOOL GetStringTypeExW(
  [in]  LCID                          Locale,
  [in]  DWORD                         dwInfoType,
  [in]  _In_NLS_string_(cchSrc)LPCWCH lpSrcStr,
  [in]  int                           cchSrc,
  [out] LPWORD                        lpCharType
);