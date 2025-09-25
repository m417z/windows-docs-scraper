NTSTATUS HidP_UsageListDifference(
  [in]  PUSAGE PreviousUsageList,
  [in]  PUSAGE CurrentUsageList,
  [out] PUSAGE BreakUsageList,
  [out] PUSAGE MakeUsageList,
  [in]  ULONG  UsageListLength
);