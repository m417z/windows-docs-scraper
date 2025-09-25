DWORD PowerReadValueIncrement(
  [in, optional] HKEY       RootPowerKey,
  [in, optional] const GUID *SubGroupOfPowerSettingsGuid,
  [in, optional] const GUID *PowerSettingGuid,
  [out]          LPDWORD    ValueIncrement
);