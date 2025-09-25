WINSETUPAPI BOOL SetupDiSetClassRegistryPropertyA(
  [in]           const GUID *ClassGuid,
  [in]           DWORD      Property,
  [in, optional] const BYTE *PropertyBuffer,
  [in]           DWORD      PropertyBufferSize,
  [in, optional] PCSTR      MachineName,
                 PVOID      Reserved
);