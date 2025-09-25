DWORD PowerEnumerate(
  [in, optional]  HKEY                RootPowerKey,
  [in, optional]  const GUID          *SchemeGuid,
  [in, optional]  const GUID          *SubGroupOfPowerSettingsGuid,
  [in]            POWER_DATA_ACCESSOR AccessFlags,
  [in]            ULONG               Index,
  [out, optional] UCHAR               *Buffer,
  [in, out]       DWORD               *BufferSize
);