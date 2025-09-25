BOOL EnumResourceLanguagesExW(
  [in] HMODULE          hModule,
  [in] LPCWSTR          lpType,
  [in] LPCWSTR          lpName,
  [in] ENUMRESLANGPROCW lpEnumFunc,
  [in] LONG_PTR         lParam,
  [in] DWORD            dwFlags,
  [in] LANGID           LangId
);