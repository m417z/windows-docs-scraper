WINSETUPAPI BOOL SetupGetInfPublishedNameA(
  [in]            PCSTR  DriverStoreLocation,
  [out]           PSTR   ReturnBuffer,
  [in]            DWORD  ReturnBufferSize,
  [out, optional] PDWORD RequiredSize
);