PDH_FUNCTION PdhMakeCounterPathW(
  [in]      PPDH_COUNTER_PATH_ELEMENTS_W pCounterPathElements,
  [out]     LPWSTR                       szFullPathBuffer,
  [in, out] LPDWORD                      pcchBufferSize,
  [in]      DWORD                        dwFlags
);