NTSYSAPI ULONG RtlFindClearRuns(
  [in]  PRTL_BITMAP     BitMapHeader,
  [out] PRTL_BITMAP_RUN RunArray,
  [in]  ULONG           SizeOfRunArray,
  [in]  BOOLEAN         LocateLongestRuns
);