WINSETUPAPI BOOL SetupDiGetClassRegistryPropertyW(
  [in]            const GUID *ClassGuid,
  [in]            DWORD      Property,
  [out, optional] PDWORD     PropertyRegDataType,
  [out]           PBYTE      PropertyBuffer,
  [in]            DWORD      PropertyBufferSize,
  [out, optional] PDWORD     RequiredSize,
  [in, optional]  PCWSTR     MachineName,
                  PVOID      Reserved
);