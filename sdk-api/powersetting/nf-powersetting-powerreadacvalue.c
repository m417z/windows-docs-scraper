DWORD PowerReadACValue(
  [in, optional]      HKEY       RootPowerKey,
  [in, optional]      const GUID *SchemeGuid,
  [in, optional]      const GUID *SubGroupOfPowerSettingsGuid,
  [in, optional]      const GUID *PowerSettingGuid,
  [out, optional]     PULONG     Type,
  [out, optional]     LPBYTE     Buffer,
  [in, out, optional] LPDWORD    BufferSize
);