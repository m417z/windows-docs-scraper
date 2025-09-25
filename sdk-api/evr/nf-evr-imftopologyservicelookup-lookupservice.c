HRESULT LookupService(
  [in]      MF_SERVICE_LOOKUP_TYPE Type,
  [in]      DWORD                  dwIndex,
  [in]      REFGUID                guidService,
  [in]      REFIID                 riid,
  [out]     LPVOID                 *ppvObjects,
  [in, out] DWORD                  *pnObjects
);