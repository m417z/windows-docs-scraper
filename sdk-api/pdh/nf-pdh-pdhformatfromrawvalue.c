PDH_FUNCTION PdhFormatFromRawValue(
  [in]  DWORD                 dwCounterType,
  [in]  DWORD                 dwFormat,
  [in]  LONGLONG              *pTimeBase,
  [in]  PPDH_RAW_COUNTER      pRawValue1,
  [in]  PPDH_RAW_COUNTER      pRawValue2,
  [out] PPDH_FMT_COUNTERVALUE pFmtValue
);