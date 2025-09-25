PDH_FUNCTION PdhCalculateCounterFromRawValue(
  [in]  PDH_HCOUNTER          hCounter,
  [in]  DWORD                 dwFormat,
  [in]  PPDH_RAW_COUNTER      rawValue1,
  [in]  PPDH_RAW_COUNTER      rawValue2,
  [out] PPDH_FMT_COUNTERVALUE fmtValue
);