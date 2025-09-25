int FoldStringW(
  [in]            DWORD                         dwMapFlags,
  [in]            _In_NLS_string_(cchSrc)LPCWCH lpSrcStr,
  [in]            int                           cchSrc,
  [out, optional] LPWSTR                        lpDestStr,
  [in]            int                           cchDest
);