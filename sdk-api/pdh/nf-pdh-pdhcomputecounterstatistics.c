PDH_FUNCTION PdhComputeCounterStatistics(
  [in]  PDH_HCOUNTER     hCounter,
  [in]  DWORD            dwFormat,
  [in]  DWORD            dwFirstEntry,
  [in]  DWORD            dwNumEntries,
  [in]  PPDH_RAW_COUNTER lpRawValueArray,
  [out] PPDH_STATISTICS  data
);