DWORD PowerWriteACValueIndex(
  [in, optional] HKEY       RootPowerKey,
  [in]           const GUID *SchemeGuid,
  [in, optional] const GUID *SubGroupOfPowerSettingsGuid,
  [in, optional] const GUID *PowerSettingGuid,
  [in]           DWORD      AcValueIndex
);