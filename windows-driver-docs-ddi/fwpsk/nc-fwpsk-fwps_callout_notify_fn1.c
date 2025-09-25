FWPS_CALLOUT_NOTIFY_FN1 FwpsCalloutNotifyFn1;

NTSTATUS FwpsCalloutNotifyFn1(
  [in] FWPS_CALLOUT_NOTIFY_TYPE notifyType,
  [in] const GUID *filterKey,
  [in] FWPS_FILTER1 *filter
)
{...}