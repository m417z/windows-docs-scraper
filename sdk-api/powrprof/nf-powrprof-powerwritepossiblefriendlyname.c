DWORD PowerWritePossibleFriendlyName(
  [in, optional] HKEY       RootPowerKey,
  [in, optional] const GUID *SubGroupOfPowerSettingsGuid,
  [in, optional] const GUID *PowerSettingGuid,
  [in]           ULONG      PossibleSettingIndex,
  [in]           UCHAR      *Buffer,
  [in]           DWORD      BufferSize
);