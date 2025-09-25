BOOL QueryActCtxSettingsW(
  [in, optional]  DWORD  dwFlags,
  [in, optional]  HANDLE hActCtx,
  [in, optional]  PCWSTR settingsNameSpace,
  [in]            PCWSTR settingName,
  [out]           PWSTR  pvBuffer,
  [in]            SIZE_T dwBuffer,
  [out, optional] SIZE_T *pdwWrittenOrRequired
);