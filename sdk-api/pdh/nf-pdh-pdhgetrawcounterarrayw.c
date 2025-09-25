PDH_FUNCTION PdhGetRawCounterArrayW(
  [in]      PDH_HCOUNTER            hCounter,
  [in, out] LPDWORD                 lpdwBufferSize,
  [out]     LPDWORD                 lpdwItemCount,
  [out]     PPDH_RAW_COUNTER_ITEM_W ItemBuffer
);