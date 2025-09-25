DWORD PowerReadFriendlyName(
  [in, optional]  HKEY       RootPowerKey,
  [in, optional]  const GUID *SchemeGuid,
  [in, optional]  const GUID *SubGroupOfPowerSettingsGuid,
  [in, optional]  const GUID *PowerSettingGuid,
  [out, optional] PUCHAR     Buffer,
  [in, out]       LPDWORD    BufferSize
);