int WideCharToMultiByte(
  [in]            UINT                               CodePage,
  [in]            DWORD                              dwFlags,
  [in]            _In_NLS_string_(cchWideChar)LPCWCH lpWideCharStr,
  [in]            int                                cchWideChar,
  [out, optional] LPSTR                              lpMultiByteStr,
  [in]            int                                cbMultiByte,
  [in, optional]  LPCCH                              lpDefaultChar,
  [out, optional] LPBOOL                             lpUsedDefaultChar
);