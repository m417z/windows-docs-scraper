WINSETUPAPI BOOL SetupGetInfDriverStoreLocationA(
  [in]            PCSTR                FileName,
  [in, optional]  PSP_ALTPLATFORM_INFO AlternatePlatformInfo,
  [in, optional]  PCSTR                LocaleName,
  [out]           PSTR                 ReturnBuffer,
  [in]            DWORD                ReturnBufferSize,
  [out, optional] PDWORD               RequiredSize
);