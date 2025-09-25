DWORD PowerWriteValueUnitsSpecifier(
  [in, optional] HKEY       RootPowerKey,
  [in, optional] const GUID *SubGroupOfPowerSettingsGuid,
  [in, optional] const GUID *PowerSettingGuid,
  [in]           UCHAR      *Buffer,
  [in]           DWORD      BufferSize
);