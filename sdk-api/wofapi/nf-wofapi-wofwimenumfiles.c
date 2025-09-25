HRESULT WofWimEnumFiles(
  [in]           PCWSTR           VolumeName,
  [in]           LARGE_INTEGER    DataSourceId,
  [in]           WofEnumFilesProc EnumProc,
  [in, optional] PVOID            UserData
);