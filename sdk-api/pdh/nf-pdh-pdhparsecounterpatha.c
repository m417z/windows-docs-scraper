PDH_FUNCTION PdhParseCounterPathA(
  [in]      LPCSTR                       szFullPathBuffer,
  [out]     PPDH_COUNTER_PATH_ELEMENTS_A pCounterPathElements,
  [in, out] LPDWORD                      pdwBufferSize,
            DWORD                        dwFlags
);