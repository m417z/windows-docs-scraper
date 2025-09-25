FWPS_CALLOUT_CLASSIFY_FN1 FwpsCalloutClassifyFn1;

void FwpsCalloutClassifyFn1(
  const FWPS_INCOMING_VALUES0 *inFixedValues,
  const FWPS_INCOMING_METADATA_VALUES0 *inMetaValues,
  void *layerData,
  const void *classifyContext,
  const FWPS_FILTER1 *filter,
  UINT64 flowContext,
  FWPS_CLASSIFY_OUT0 *classifyOut
)
{...}