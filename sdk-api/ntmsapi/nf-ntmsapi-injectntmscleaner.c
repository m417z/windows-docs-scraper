DWORD InjectNtmsCleaner(
  [in]      HANDLE      hSession,
  [in]      LPNTMS_GUID lpLibrary,
  [in, out] LPNTMS_GUID lpInjectOperation,
  [out]     DWORD       dwNumberOfCleansLeft,
  [in]      DWORD       dwAction
);