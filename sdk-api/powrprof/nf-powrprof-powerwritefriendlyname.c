DWORD PowerWriteFriendlyName(
  [in, optional] HKEY       RootPowerKey,
  [in]           const GUID *SchemeGuid,
  [in, optional] const GUID *SubGroupOfPowerSettingsGuid,
  [in, optional] const GUID *PowerSettingGuid,
  [in]           UCHAR      *Buffer,
  [in]           DWORD      BufferSize
);