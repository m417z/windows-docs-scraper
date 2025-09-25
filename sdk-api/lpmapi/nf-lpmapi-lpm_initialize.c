ULONG LPM_Initialize(
  [in]  LPM_HANDLE    LpmHandle,
  [in]  LPM_INIT_INFO *pLpmInitInfo,
  [out] DWORD         *pLpmVersionNumber,
  [out] PETYPE        *pSupportedPeType,
  [out] VOID          *Reserved
);