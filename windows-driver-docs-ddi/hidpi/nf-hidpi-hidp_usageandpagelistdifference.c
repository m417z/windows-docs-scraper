NTSTATUS HidP_UsageAndPageListDifference(
  [in, reads]   PUSAGE_AND_PAGE PreviousUsageList,
  [in, reads]   PUSAGE_AND_PAGE CurrentUsageList,
  [out, writes] PUSAGE_AND_PAGE BreakUsageList,
  [out, writes] PUSAGE_AND_PAGE MakeUsageList,
  [in]          ULONG           UsageListLength
);