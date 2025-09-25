FWPS_CALLOUT_CLASSIFY_FN2 FwpsCalloutClassifyFn2;

void FwpsCalloutClassifyFn2(
  const FWPS_INCOMING_VALUES0 *inFixedValues,
  const FWPS_INCOMING_METADATA_VALUES0 *inMetaValues,
  void *layerData,
  const void *classifyContext,
  const FWPS_FILTER2 *filter,
  UINT64 flowContext,
  FWPS_CLASSIFY_OUT0 *classifyOut
)
{...}