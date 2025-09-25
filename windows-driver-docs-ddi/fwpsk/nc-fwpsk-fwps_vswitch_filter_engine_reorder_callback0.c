FWPS_VSWITCH_FILTER_ENGINE_REORDER_CALLBACK0 FwpsVswitchFilterEngineReorderCallback0;

NTSTATUS FwpsVswitchFilterEngineReorderCallback0(
  [in, optional] void *notifyContext,
  [in]           void *completionContext,
  [in]           BOOLEAN isInRequiredPosition,
  [in]           const NDIS_ENUM_FILTERS *vSwitchExtensionLwfList
)
{...}