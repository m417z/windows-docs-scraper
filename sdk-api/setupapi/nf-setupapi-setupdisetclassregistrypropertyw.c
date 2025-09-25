WINSETUPAPI BOOL SetupDiSetClassRegistryPropertyW(
  [in]           const GUID *ClassGuid,
  [in]           DWORD      Property,
  [in, optional] const BYTE *PropertyBuffer,
  [in]           DWORD      PropertyBufferSize,
  [in, optional] PCWSTR     MachineName,
                 PVOID      Reserved
);