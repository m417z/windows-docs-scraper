FWPS_CALLOUT_NOTIFY_FN0 FwpsCalloutNotifyFn0;

NTSTATUS FwpsCalloutNotifyFn0(
  [in] FWPS_CALLOUT_NOTIFY_TYPE notifyType,
  [in] const GUID *filterKey,
  [in] FWPS_FILTER0 *filter
)
{...}