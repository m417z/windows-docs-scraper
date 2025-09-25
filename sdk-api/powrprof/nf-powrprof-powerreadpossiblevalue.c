DWORD PowerReadPossibleValue(
  [in, optional]  HKEY       RootPowerKey,
  [in, optional]  const GUID *SubGroupOfPowerSettingsGuid,
  [in, optional]  const GUID *PowerSettingGuid,
  [out, optional] PULONG     Type,
  [in]            ULONG      PossibleSettingIndex,
  [out, optional] PUCHAR     Buffer,
  [in, out]       LPDWORD    BufferSize
);