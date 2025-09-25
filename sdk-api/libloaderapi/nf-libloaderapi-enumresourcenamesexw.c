BOOL EnumResourceNamesExW(
  [in, optional] HMODULE          hModule,
                 LPCWSTR          lpType,
  [in]           ENUMRESNAMEPROCW lpEnumFunc,
  [in]           LONG_PTR         lParam,
  [in]           DWORD            dwFlags,
  [in]           LANGID           LangId
);