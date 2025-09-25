VOID WdfRequestCompleteWithPriorityBoost(
  [in] WDFREQUEST Request,
  [in] NTSTATUS   Status,
  [in] CCHAR      PriorityBoost
);