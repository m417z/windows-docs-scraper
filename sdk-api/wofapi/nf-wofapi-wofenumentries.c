HRESULT WofEnumEntries(
  [in]           PCWSTR           VolumeName,
  [in]           ULONG            Provider,
  [in]           WofEnumEntryProc EnumProc,
  [in, optional] PVOID            UserData
);