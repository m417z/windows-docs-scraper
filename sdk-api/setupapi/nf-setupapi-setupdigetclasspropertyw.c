WINSETUPAPI BOOL SetupDiGetClassPropertyW(
  [in]            const GUID       *ClassGuid,
  [in]            const DEVPROPKEY *PropertyKey,
  [out]           DEVPROPTYPE      *PropertyType,
  [out]           PBYTE            PropertyBuffer,
  [in]            DWORD            PropertyBufferSize,
  [out, optional] PDWORD           RequiredSize,
  [in]            DWORD            Flags
);