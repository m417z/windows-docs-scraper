DWORD PowerReadPossibleDescription(
  [in, optional]  HKEY       RootPowerKey,
  [in, optional]  const GUID *SubGroupOfPowerSettingsGuid,
  [in, optional]  const GUID *PowerSettingGuid,
  [in]            ULONG      PossibleSettingIndex,
  [out, optional] PUCHAR     Buffer,
  [in, out]       LPDWORD    BufferSize
);