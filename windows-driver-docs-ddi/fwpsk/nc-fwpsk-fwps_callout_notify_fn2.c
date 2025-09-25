FWPS_CALLOUT_NOTIFY_FN2 FwpsCalloutNotifyFn2;

NTSTATUS FwpsCalloutNotifyFn2(
  [in]      FWPS_CALLOUT_NOTIFY_TYPE notifyType,
  [in]      const GUID *filterKey,
  [in, out] FWPS_FILTER2 *filter
)
{...}