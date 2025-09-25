DWORD PowerReadDCDefaultIndex(
  [in, optional] HKEY       RootPowerKey,
  [in]           const GUID *SchemePersonalityGuid,
  [in, optional] const GUID *SubGroupOfPowerSettingsGuid,
  [in]           const GUID *PowerSettingGuid,
  [out]          LPDWORD    DcDefaultIndex
);