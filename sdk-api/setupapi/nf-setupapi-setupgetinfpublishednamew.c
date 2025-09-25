WINSETUPAPI BOOL SetupGetInfPublishedNameW(
  [in]            PCWSTR DriverStoreLocation,
  [out]           PWSTR  ReturnBuffer,
  [in]            DWORD  ReturnBufferSize,
  [out, optional] PDWORD RequiredSize
);