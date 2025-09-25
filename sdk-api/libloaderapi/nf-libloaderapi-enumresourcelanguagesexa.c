BOOL EnumResourceLanguagesExA(
  [in] HMODULE          hModule,
  [in] LPCSTR           lpType,
  [in] LPCSTR           lpName,
  [in] ENUMRESLANGPROCA lpEnumFunc,
  [in] LONG_PTR         lParam,
  [in] DWORD            dwFlags,
  [in] LANGID           LangId
);