DWORD PowerWriteValueMin(
  [in, optional] HKEY       RootPowerKey,
  [in, optional] const GUID *SubGroupOfPowerSettingsGuid,
  [in, optional] const GUID *PowerSettingGuid,
  [in]           DWORD      ValueMinimum
);