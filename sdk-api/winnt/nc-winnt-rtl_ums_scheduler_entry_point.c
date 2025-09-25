RTL_UMS_SCHEDULER_ENTRY_POINT RtlUmsSchedulerEntryPoint;

VOID RtlUmsSchedulerEntryPoint(
  [in] RTL_UMS_SCHEDULER_REASON Reason,
  [in] ULONG_PTR ActivationPayload,
  [in] PVOID SchedulerParam
)
{...}