WINSETUPAPI BOOL SetupDiSetClassPropertyW(
  [in]           const GUID       *ClassGuid,
  [in]           const DEVPROPKEY *PropertyKey,
  [in]           DEVPROPTYPE      PropertyType,
  [in, optional] const PBYTE      PropertyBuffer,
  [in]           DWORD            PropertyBufferSize,
  [in]           DWORD            Flags
);