HRESULT WofFileEnumFiles(
  [in]           PCWSTR           VolumeName,
  [in]           ULONG            Algorithm,
  [in]           WofEnumFilesProc EnumProc,
  [in, optional] PVOID            UserData
);