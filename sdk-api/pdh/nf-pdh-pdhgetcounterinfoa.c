PDH_FUNCTION PdhGetCounterInfoA(
  [in]      PDH_HCOUNTER        hCounter,
  [in]      BOOLEAN             bRetrieveExplainText,
  [in, out] LPDWORD             pdwBufferSize,
  [out]     PPDH_COUNTER_INFO_A lpBuffer
);