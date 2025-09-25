FWPS_CALLOUT_NOTIFY_FN1 FwpsCalloutNotifyFn1;

NTSTATUS FwpsCalloutNotifyFn1(
  FWPS_CALLOUT_NOTIFY_TYPE notifyType,
  const GUID *filterKey,
  FWPS_FILTER1 *filter
)
{...}