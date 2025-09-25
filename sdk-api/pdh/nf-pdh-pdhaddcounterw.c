PDH_FUNCTION PdhAddCounterW(
  [in]  PDH_HQUERY   hQuery,
  [in]  LPCWSTR      szFullCounterPath,
  [in]  DWORD_PTR    dwUserData,
  [out] PDH_HCOUNTER *phCounter
);