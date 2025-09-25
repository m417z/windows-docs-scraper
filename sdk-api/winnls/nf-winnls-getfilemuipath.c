BOOL GetFileMUIPath(
  [in]                DWORD      dwFlags,
  [in]                PCWSTR     pcwszFilePath,
  [in, out, optional] PWSTR      pwszLanguage,
  [in, out]           PULONG     pcchLanguage,
  [out, optional]     PWSTR      pwszFileMUIPath,
  [in, out]           PULONG     pcchFileMUIPath,
  [in, out]           PULONGLONG pululEnumerator
);