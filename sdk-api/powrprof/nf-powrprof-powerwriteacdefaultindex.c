DWORD PowerWriteACDefaultIndex(
  [in, optional] HKEY       RootSystemPowerKey,
  [in]           const GUID *SchemePersonalityGuid,
  [in, optional] const GUID *SubGroupOfPowerSettingsGuid,
  [in]           const GUID *PowerSettingGuid,
  [in]           DWORD      DefaultAcIndex
);