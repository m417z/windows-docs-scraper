WINSETUPAPI BOOL SetupDiGetClassPropertyExW(
  [in]            const GUID       *ClassGuid,
  [in]            const DEVPROPKEY *PropertyKey,
  [out]           DEVPROPTYPE      *PropertyType,
  [out, optional] PBYTE            PropertyBuffer,
  [in]            DWORD            PropertyBufferSize,
  [out, optional] PDWORD           RequiredSize,
  [in]            DWORD            Flags,
  [in, optional]  PCWSTR           MachineName,
                  PVOID            Reserved
);