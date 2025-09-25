DWORD PowerReadValueUnitsSpecifier(
  [in, optional]  HKEY       RootPowerKey,
  [in, optional]  const GUID *SubGroupOfPowerSettingsGuid,
  [in, optional]  const GUID *PowerSettingGuid,
  [out, optional] UCHAR      *Buffer,
  [in, out]       LPDWORD    BufferSize
);