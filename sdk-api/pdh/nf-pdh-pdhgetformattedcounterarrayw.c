PDH_FUNCTION PdhGetFormattedCounterArrayW(
  [in]      PDH_HCOUNTER                 hCounter,
  [in]      DWORD                        dwFormat,
  [in, out] LPDWORD                      lpdwBufferSize,
  [out]     LPDWORD                      lpdwItemCount,
  [out]     PPDH_FMT_COUNTERVALUE_ITEM_W ItemBuffer
);