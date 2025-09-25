PDH_FUNCTION PdhParseCounterPathW(
  [in]      LPCWSTR                      szFullPathBuffer,
  [out]     PPDH_COUNTER_PATH_ELEMENTS_W pCounterPathElements,
  [in, out] LPDWORD                      pdwBufferSize,
            DWORD                        dwFlags
);