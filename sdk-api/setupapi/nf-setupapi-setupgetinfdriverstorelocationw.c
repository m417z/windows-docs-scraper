WINSETUPAPI BOOL SetupGetInfDriverStoreLocationW(
  [in]            PCWSTR               FileName,
  [in, optional]  PSP_ALTPLATFORM_INFO AlternatePlatformInfo,
  [in, optional]  PCWSTR               LocaleName,
  [out]           PWSTR                ReturnBuffer,
  [in]            DWORD                ReturnBufferSize,
  [out, optional] PDWORD               RequiredSize
);