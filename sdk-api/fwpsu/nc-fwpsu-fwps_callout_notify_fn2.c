FWPS_CALLOUT_NOTIFY_FN2 FwpsCalloutNotifyFn2;

NTSTATUS FwpsCalloutNotifyFn2(
  FWPS_CALLOUT_NOTIFY_TYPE notifyType,
  const GUID *filterKey,
  FWPS_FILTER2 *filter
)
{...}