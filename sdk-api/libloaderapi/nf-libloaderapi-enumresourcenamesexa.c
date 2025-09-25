BOOL EnumResourceNamesExA(
  [in, optional] HMODULE          hModule,
                 LPCSTR           lpType,
  [in]           ENUMRESNAMEPROCA lpEnumFunc,
  [in]           LONG_PTR         lParam,
  [in]           DWORD            dwFlags,
  [in]           LANGID           LangId
);