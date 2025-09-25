WINSETUPAPI BOOL SetupDiGetClassRegistryPropertyA(
  [in]            const GUID *ClassGuid,
  [in]            DWORD      Property,
  [out, optional] PDWORD     PropertyRegDataType,
  [out]           PBYTE      PropertyBuffer,
  [in]            DWORD      PropertyBufferSize,
  [out, optional] PDWORD     RequiredSize,
  [in, optional]  PCSTR      MachineName,
                  PVOID      Reserved
);